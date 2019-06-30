! Fortran Matrix Multiply
! Nick Michael

PROGRAM MAIN
    REAL, DIMENSION(10000, 10000) :: a, b, c
    REAL :: start, finish
    CALL POPULATE(a, b)
    CALL CPU_TIME(start)
    c = MATMUL(a,b)
    !CALL MULTIPLY(a, b, c)
    CALL CPU_TIME(finish)
    print*,finish-start
END PROGRAM MAIN

SUBROUTINE POPULATE(x, y)
    REAL, DIMENSION(10000, 10000) :: x, y
    INTEGER :: i, j
    REAL :: zi, zj
    do j=1,10000
        do i=1,10000
            zi = i
            zj = j
            zi = zi/10000
            zj = zj/10000
            x(i,j) = (zi**2 + zj**2)/2.0
            y(i,j) = (zi*zj + zi*zj)/2.0
        end do
    end do
END SUBROUTINE POPULATE

SUBROUTINE MULTIPLY(x, y, z)
    REAL :: start, finish
    REAL, DIMENSION(10000, 10000) :: x, y, z
    INTEGER :: i, j
    CALL CPU_TIME(start)
    do i=1,10000
        do j=1,10000
            z(i,j) = DOT_PRODUCT(x(:,i),y(j,:))
        end do
    end do
    CALL CPU_TIME(finish)
    print *, (finish-start)
END SUBROUTINE MULTIPLY

