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
    # print(board)


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
        return
    for n in range(1, 10):
        if possible(board, i, j, n):
            board[i, j] = n
            solveSmartBacktracking(board)
            board[i, j] = 0
    smartBacktrack += 1


if __name__ == "__main__":
    board = np.array([[5, 3, 0, 0, 7, 0, 0, 0, 0],
                      [6, 0, 0, 1, 9, 5, 0, 0, 0],
                      [0, 9, 8, 0, 0, 0, 0, 6, 0],
                      [8, 0, 0, 0, 6, 0, 0, 0, 3],
                      [4, 0, 0, 8, 0, 3, 0, 0, 1],
                      [7, 0, 0, 0, 2, 0, 0, 0, 6],
                      [0, 6, 0, 0, 0, 0, 2, 8, 0],
                      [0, 0, 0, 4, 1, 9, 0, 0, 5],
                      [0, 0, 0, 0, 8, 0, 0, 7, 9]])
    startTime = time.time_ns()
    solveBacktracking(board)
    runningTime = time.time_ns() - startTime
    print("Backtracking:", runningTime/1e9)
    print("Number of backtrack:", backtrack)
    board1 = np.array([[5, 3, 0, 0, 7, 0, 0, 0, 0],
                       [6, 0, 0, 1, 9, 5, 0, 0, 0],
                       [0, 9, 8, 0, 0, 0, 0, 6, 0],
                       [8, 0, 0, 0, 6, 0, 0, 0, 3],
                       [4, 0, 0, 8, 0, 3, 0, 0, 1],
                       [7, 0, 0, 0, 2, 0, 0, 0, 6],
                       [0, 6, 0, 0, 0, 0, 2, 8, 0],
                       [0, 0, 0, 4, 1, 9, 0, 0, 5],
                       [0, 0, 0, 0, 8, 0, 0, 7, 9]])
    startTime = time.time_ns()
    solveSmartBacktracking(board1)
    runningTime = time.time_ns() - startTime
    print("Smart Backtracking:", runningTime/1e9)
    print("Number of backtrack:", smartBacktrack)
