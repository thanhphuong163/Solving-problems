import numpy as np
import time


def possible(board, row, col, n):
    if n in board[row, :]:
        return False
    if n in board[:, col]:
        return False
    blRow = row//3
    blCol = col//3
    if n in board[blRow*3: (blRow+1)*3, blCol*3: (blCol+1)*3]:
        return False
    return True

backtrack = 0
def solveBacktracking(board):
    global backtrack
    for i in range(0, 9):
        for j in range(0, 9):
            if board[i, j] == 0:
                for n in range(1, 10):
                    if possible(board, i, j, n):
                        board[i, j] = n
                        solveBacktracking(board)
                        board[i, j] = 0
                backtrack += 1
                return
    print("Stupid backtracking:", backtrack, "backtracks")


def chooseCell(board):
    col = -1
    row = -1
    minOpt = 1000
    for i in range(0, 9):
        for j in range(0, 9):
            count = 0
            if board[i, j] == 0:
                for n in range(1, 10):
                    if possible(board, i, j, n):
                        count += 1
                if count < minOpt:
                    row = i
                    col = j
                    minOpt = count
    return (row, col)

smartBacktrack = 0
def solveSmartBacktracking(board):
    global smartBacktrack
    i, j = chooseCell(board)
    if (i == -1):
        print("Smart backtracking:", smartBacktrack, "backtracks")
        return
    for n in range(1, 10):
        if possible(board, i, j, n):
            board[i, j] = n
            solveSmartBacktracking(board)
            board[i, j] = 0
    smartBacktrack += 1


if __name__ == "__main__":
    boards = []
    with open('sudoku.txt', 'r') as f:
        t = f.readline()
        for i in range(0, int(t)):
            difficulty = f.readline().strip()
            board = []
            for i in range(0,9):
                line = f.readline().strip().split(' ')
                board.append([int(i) for i in line])
            boards.append({"difficulty": difficulty, "board": np.array(board)})
    for board in boards:
        print(board["difficulty"])
        solveSmartBacktracking(board["board"].copy())
        solveBacktracking(board["board"].copy())
