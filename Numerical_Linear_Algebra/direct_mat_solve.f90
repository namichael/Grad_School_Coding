! Nick Michael

PROGRAM MAIN

    IMPLICIT NONE

    INTEGER, PARAMETER :: np = 4
    REAL, DIMENSION(np, np+1) :: mat_a
    REAL, DIMENSION(np)    :: vec_x = 0

    mat_a = RESHAPE((/ 4, 1, -1, 1, 1, 4, -1, -1, -1, -1, &
        & 5, 1, 1, -1, 1 ,3, -2, -1, 0, 1 /), SHAPE(mat_a))
    CALL DIRECT_SOLVE(mat_a, vec_x, np)

    WRITE(*,*)
    WRITE(*,*) vec_x
    WRITE(*,*)

END PROGRAM MAIN


SUBROUTINE DIRECT_SOLVE(a, x, n)

    IMPLICIT NONE

    INTEGER, INTENT(in) :: n
    INTEGER :: i, j
    REAL, DIMENSION(n, n+1), INTENT(inout) :: a
    REAL, DIMENSION(n), INTENT(out) :: x

    ! Forward Substitution
    DO i = 1, n-1
        a(i+1:n,i) = a(i+1:n,i)/a(i,i)
        DO j = i+1, n+1
            ! vectorize by column to ensure cache efficiency
            a(i+1:n,j) = a(i+1:n,j) - a(i,j)*a(i+1:n,i)
        END DO
        a(i+1:n,i) = 0
    END DO

    ! Set Diagonals to 1.0
    DO i = 1, n
        a(i,i+1:n+1) = a(i,i+1:n+1)/a(i,i)
        a(i,i) = 1.0
    END DO

    ! Backward Substitution
    DO i = 1, n
        a(1:n-i,n+1) = a(1:n-i,n+1) - a(n-i+1,n+1)*a(1:n-i,n-i+1)
        a(1:n-i,n-i+1) = 0
    END DO

    ! Set X equall to final column in A
    x = a(:,n+1)

END SUBROUTINE DIRECT_SOLVE