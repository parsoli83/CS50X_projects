"""
Flask tutorial

some basic starter stuff:

from flask import Flask,render_template,request

app = Flask(__name__)

@app.route("/")
def index_page():
    if "name" in request.args:
        name = request.args["name"]
    else:
        name = world
    return "hello " + name

in the foulder run this
--> flask run


the html files should be kept in templates folder
and you can link different back-end routes together with "/route" type style

#it has both index.html and greet.html


from flask import Flask,render_template,request

app = Flask(__name__)

@app.route("/")
def index_page():
    return render_template("index.html")


@app.route("/greet")
def greet():
    return render_template("greet.html",name=request.args.get("name"))
"""

from cs50 import SQL
from flask import Flask,render_template,request

app = Flask(__name__)

@app.route("/")
def index_page():
    return render_template("index.html")


@app.route("/register",methods=["POST"])
def greet():
    name = request.form.get("name")
    return render_template("greet.html",name=name)
    