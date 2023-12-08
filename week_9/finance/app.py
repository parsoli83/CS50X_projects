import os
from time import time
from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    l_all = db.execute(f"SELECT * FROM history WHERE user_id = {session['user_id']}")
    owned_shares = []
    properties = []
    print("#"*50)
    print(l_all)
    print("#"*50)
    for transaction in l_all:
        if transaction["symbol"] not in owned_shares:
            looked = lookup(transaction["symbol"])
            owned_shares.append(transaction["symbol"])
            if transaction["action"]=="buy":
                properties.append([transaction["shares"],looked["price"]])
            else:
                properties.append([-1*transaction["shares"],looked["price"]])
        else:
            i = owned_shares.index(transaction["symbol"])
            print("#"*50)
            print("i= ",i)
            print("#"*50)
            if transaction["action"]=="buy":
                properties[i][0]+=transaction["shares"]
            else:
                properties[i][0]-=transaction["shares"]
    sum = 0
    for i in properties:
        sum+= i[0]*i[1]
    cash = db.execute(f"SELECT cash FROM users WHERE id={session['user_id']}")[0]["cash"]
    for i in properties:
        i.append(usd(i[0]*i[1]))
    
    return render_template("index.html",cash=usd(cash),sum=usd(sum),l = len(properties),owned_shares=owned_shares,properties=properties)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")
        print(f"symbol: {symbol}")
        print(f"shares: {shares}")
        
        if not shares or not symbol:
            return apology("dont leave fields blank")
        try:
            shares= int(shares)
            if shares<1:
                return apology("invalid value of shares")
            looked = lookup(symbol)
            print(f"looked: {looked}")
            if not looked:
                return apology("invalid share symbol")
            print(f"user_id: {session['user_id']}")
            cash = db.execute(f"SELECT cash FROM users WHERE id={session['user_id']}")[0]["cash"]
            print("######################################")
            print(f"cash: {cash}")
            if cash<looked["price"]*shares:
                return apology("not enough money")
            db.execute(f"UPDATE users SET cash={cash-looked['price']*shares} WHERE id = {session['user_id']}")
            timestamp = int(time())
            print(f"timestamp: {timestamp}")
            db.execute(f'INSERT INTO history(user_id,symbol,shares,action,price,time) '+
            f'VALUES ({session["user_id"]},"{symbol}",{shares},"buy",{looked["price"]},{timestamp})')
            return redirect("/")
        except:
            return apology("fucked up")
    return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    l_all = db.execute(f"SELECT * FROM history WHERE user_id = {session['user_id']}")
    return render_template("history.html",l_all=l_all)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    try:
        if request.method== "POST" :
            symbol = request.form.get("symbol")
            if not symbol:
                return apology("no symbol provided",400)
            else:
                looked = lookup(symbol)
                print(looked)
                if looked == None:
                    return apology("no such symbol",400)
                looked["price"]=usd(looked["price"])
                return render_template("quoted.html",looked=looked)
        return render_template("quote.html")
    except:
        return apology("meow",400)

@app.route("/register", methods=["GET", "POST"])
def register():

    """Register user"""
    session.clear()
    user_names = db.execute("SELECT username FROM users")
    print(user_names)

    try:
        if request.method == "POST":
            user_name=request.form.get("username")
            pass_word=request.form.get("password")
            con_firmation=request.form.get("confirmation")
            # Ensure username was submitted
            if not user_name:
                return apology("must provide username", 400)
            elif user_name in user_names:
                return apology("duplicate username", 400)
            # Ensure password was submitted
            elif not pass_word:
                return apology("must provide password", 400)
            elif not con_firmation:
                return apology("must provide confirmation", 400)
            elif con_firmation!=pass_word:
                return apology("password and confirmation should match", 400)
            elif len(pass_word)<5:
                return apology("short password")
            key1=False
            key2=False
            for i in pass_word:
                if i.isnumeric():
                    key1=True
                if not i.isalnum():
                    key2=True
            if not key1 or not key2:
                return apology("must have both numbers and symbols")
            
            
            
            
            else:
                print(user_name,pass_word,con_firmation)
                pass_hash  = generate_password_hash(pass_word)
                db.execute(f"INSERT INTO users(username,hash) VALUES('{user_name}','{pass_hash}')")
                return redirect("/")
        else:
            return render_template("register.html")
    except:
        return apology("meow")



@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    l_all = db.execute(f"SELECT * FROM history WHERE user_id = {session['user_id']}")
    owned_shares = []
    properties = []
    print("#"*50)
    print(l_all)
    print("#"*50)
    for transaction in l_all:
        if transaction["symbol"] not in owned_shares:
            looked = lookup(transaction["symbol"])
            owned_shares.append(transaction["symbol"])
            if transaction["action"]=="buy":
                properties.append([transaction["shares"],looked["price"]])
            else:
                properties.append([-1*transaction["shares"],looked["price"]])
        else:
            i = owned_shares.index(transaction["symbol"])
            print("#"*50)
            print("i= ",i)
            print("#"*50)
            if transaction["action"]=="buy":
                properties[i][0]+=transaction["shares"]
            else:
                properties[i][0]-=transaction["shares"]

    print("#"*50)
    print(owned_shares)
    print(properties)
    print("#"*50)

    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")
        print(f"symbol: {symbol}")
        print(f"shares: {shares}")
        
        if not shares or not symbol:
            return apology("dont leave fields blank")
        if int(properties[owned_shares.index(symbol)][0])<int(shares):
            return apology("not enough shares")
        try:
            shares= int(shares)
            if shares<1:
                return apology("invalid value of shares")
            looked = lookup(symbol)
            print(f"looked: {looked}")
            if not looked:
                return apology("invalid share symbol")
            print(f"user_id: {session['user_id']}")
            timestamp = int(time())
            db.execute(f'INSERT INTO history(user_id,symbol,shares,action,price,time) '+
            f'VALUES ({session["user_id"]},"{symbol}",{shares},"sell",{looked["price"]},{timestamp})')
            cash = db.execute(f"SELECT cash FROM users WHERE id={session['user_id']}")[0]["cash"]
            db.execute(f"UPDATE users SET cash={cash+looked['price']*shares} WHERE id = {session['user_id']}")
            return redirect("/")
        except:
            return apology("fucked up")
    return render_template("sell.html",owned_shares=owned_shares,properties=properties)





























