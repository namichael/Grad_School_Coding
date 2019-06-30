# Nick Michael

def main():
    import numpy as np
    import scipy.linalg as la

    A = np.array([  [10, 4, 4, 3 ],
                    [4, 20, 0, 3 ],
                    [4, 0, 21, 17],
                    [3, 3, 17, 19]  ])

    b = np.array([17, 20, -3, 24])

    L = la.cho_factor(A)            # Cholesky Facotrization
    x = la.cho_solve(L, b)          # Cholesky Solve

    return x


if __name__=="__main__":
    print
    x = main()
    print x ; print