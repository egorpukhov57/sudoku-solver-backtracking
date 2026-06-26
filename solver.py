def get_candidates(matrix, x, y):
    """Returns a list of valid numbers that can be placed at matrix[y][x]."""
    arr = [1, 2, 3, 4, 5, 6, 7, 8, 9]
    
    # Check row and column
    for i in range(9):
        if matrix[y][i] in arr: 
            arr.remove(matrix[y][i])
        if matrix[i][x] in arr: 
            arr.remove(matrix[i][x])

    # Check 3x3 sub-grid
    sr, sc = (y // 3) * 3, (x // 3) * 3
    for i in range(sr, sr + 3):
        for j in range(sc, sc + 3):
            if matrix[i][j] in arr: 
                arr.remove(matrix[i][j])
    return arr

def solve(matrix):
    """Solves the Sudoku puzzle using recursive backtracking."""
    for y in range(9):
        for x in range(9):
            if matrix[y][x] == 0:
                candidates = get_candidates(matrix, x, y)
                for num in candidates:
                    matrix[y][x] = num
                    if solve(matrix):
                        return True
                    matrix[y][x] = 0  # Backtrack
                return False
    return True

if __name__ == "__main__":
    print("Enter your Sudoku puzzle line by line (9 space-separated numbers, 0 for empty):")
    grid = []
    for _ in range(9):
        row = list(map(int, input().split()))
        grid.append(row)

    print("\nSolving...")
    if solve(grid):
        print("\nSolution found:")
        for r in grid:
            print(*(r))
    else:
        print("\nNo solution exists for this puzzle.")
