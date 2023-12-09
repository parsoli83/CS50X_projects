other = lambda x: "x" if x=="o" else "o"
def minimax(board,depth,player):
    # game neder part
    if end_game(board)==player:
        return [-1,1]
    elif end_game(board)==other(player):
        return [-1,-1]
    if depth == 0:
        return [-1,0]
    

    # worst score intitiallizer
    if player == "x":
        score = [-1,-10000]
    else:
        score = [-1,10000]

    # loop in moves
    for move in moves(board):
        this_score = minimax(play(board,move,player),depth-1,other(player))
        this_score[0]=move

        # min and max
        # x is us, o is them
        if player == "x" and this_score[1]>score[1]:
            score = this_score.copy()
        if player == "o" and this_score[1]<score[1]:
            score = this_score.copy()
    return score


def print_board(board):
    counter = -1
    for i in range(3):
        for j in range(3):
            counter+=1
            print(board[counter],"",end="")
        print()

def end_game(l):
    players=["x","o"]
    for player in players:
        if (l[4]==l[0]==l[8]==player or
        l[4]==l[2]==l[6]==player or
        l[4]==l[1]==l[7]==player or
        l[4]==l[3]==l[5]==player or
        l[0]==l[1]==l[2]==player or
        l[0]==l[3]==l[6]==player or
        l[8]==l[5]==l[2]==player or
        l[8]==l[6]==l[7]==player
        ):
            return player
    return False

def moves(board):
    l=[]
    for move in range(len(board)):
        i = board[move]
        if i=="#":
            l.append(move)
    return l

def play(board,move,player):
    l=board.copy()
    l[move]=player
    return l


def main():
    board=["#" for i in range(9)]
    player = "x"
    while True:
        print(player)
        if player =="o":
            print_board(board)
            board[int(input("your turn: "))] = "o"
        else:
            score = minimax(board,len(moves(board)),player)
            print(score)
            board[score[0]] ="x"
        if end_game(board):
            break
        player = other(player)





if __name__ == "__main__":
    main()

    