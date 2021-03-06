# Enter your code here. Read input from STDIN. Print output to STDOUT
def lcm(a, b):
    return (a*b/gcd(a, b))

def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)
    
def find_iterations(M, N, R):
    if M <N:
        least = M
    else:
        least = N
    iterations = 2* M + 2*(N - 2)
    for i in range(0,least/2):
        iterations = lcm(iterations, 2* (M-2*i) + 2*(N - 2 -2*i))
    return R%iterations

def rotate_ring(matrix,x_min, y_min, x_max, y_max):
    stored_val = matrix[x_min][y_min]
    
    for i in range(y_min, y_max):
        matrix[x_min][i] = matrix[x_min][i+1]
    for i in range(x_min, x_max):
        matrix[i][y_max] = matrix[i+1][y_max]
    for i in range(y_max, y_min, -1):
        matrix[x_max][i] = matrix[x_max][i-1]
    for i in range(x_max, x_min, -1):
        matrix[i][y_min] = matrix[i-1][y_min]
    matrix[x_min+1][y_min] = stored_val
    
    
def rotate(matrix, M, N):
    #call rotate_ring
    if M<N:
        iterations = M/2
    else:
        iterations = N/2
    
    for i in range(0, iterations):
        rotate_ring(matrix,i,i,M-1-i,N-1-i)

def print_matrix(matrix, M, N):
    for i in range(0, M):
        for j in range(0, N):
            print matrix[i][j],
        print ""

#start of main code

M, N, R = [int(x) for x in raw_input().split(" ")]

matrix = []
row = []
for i in range(0, M):
    row = [int(x) for x in raw_input().split(" ")]
    matrix.append(row)

#print_matrix(matrix, M, N)
iterations = find_iterations(M,N,R)
print iterations
'''for i in range(0, iterations):
    rotate(matrix, M, N)
print_matrix(matrix, M, N)
'''
