# HWS2P4
# by Nick Michael

# for Problem 4
def FixedPoint(x):
    p = 1
    for _ in range(5):
        p = x(p)
    return p

class fncGetter:
    # y = 1
    def xy1(self):
        import numpy as np
        sin = np.sin
        self.x = lambda z: 1 + 0.5*sin(z)
        return self.x

    # y = pi/2
    def xy2(self):
        import numpy as np
        sin = np.sin
        pi = np.pi
        self.x = lambda z: 0.5*(pi + sin(z))
        return self.x

    # y = 2
    def xy3(self):
        import numpy as np
        sin = np.sin
        self.x = lambda z: 2 + 0.5*sin(z)
        return self.x

#______________________________________
##### Input to Python Interpreter #####
#_________Problem_4____________________

#   >>> from HWS2P4 import *
#   >>> Obj = fncGetter()
#   >>> FixedPoint(Obj.xy1())
#   1.4987011335178357
#   >>> FixedPoint(Obj.xy2())
#   2.0209799694328563
#   >>> FixedPoint(Obj.xy3())
#   2.3542369884129033
#   >>>


# for Problem 7
class dfnc:
    def f(self, arr, n):
        import numpy as np
        # solve for FN
        self.darr = np.zeros(6)
        c = 0
        for i in range(5):
            self.darr[i] = c + arr[i]
            c = self.darr[i]*n
        self.darr[5] = c + arr[5]
        return self.darr

    def df(self, darr, n):
        # solve for DN
        c = 0
        for i in range(4):
            FNC = c + darr[i]
            c = FNC*n
        self.DN = c + darr[4]
        return self.DN

def Newton(narr, x):
    fnc = dfnc()
    for _ in range(10):
        fn = fnc.f(narr, x)
        dn = fnc.df(fn, x)
        x = x - fn[5]/dn
    return x

def Bairstow(n, a, u, v, itr):
    import numpy as np
    b = np.zeros(n+1)
    c = np.zeros(n+1)
    b[n] = a[n]
    c[n] = 0
    c[n-1] = a[n]
    for _ in range(itr):
        b[n-1] = a[n-1] + u*b[n]
        for i in range(n-2, -1, -1):
            b[i] = a[i] + u*b[i+1] + v*b[i+2]
            c[i] = b[i+1] + u*c[i+1] + v*c[i+2]
        Dj = c[0]*c[2] - c[1]*c[1]
        du = (c[1]*b[1] - c[2]*b[0])/Dj
        dv = (c[1]*b[0] - c[0]*b[1])/Dj
        u = u + du
        v = v + dv
    #sa = (u + pow((u*u + 4*v),0.5))/2
    #sb = (u - pow((u*u + 4*v),0.5))/2
    root = np.array([u, v])
    return root

#______________________________________
##### Input to Python Interpreter #####
#_________Problem_7____________________

#   >>> from HWS2P4 import *
#   >>> import numpy as np
#   >>> farr = np.array([3,-7,-5,1,-8,2])
#   >>> x0 = 4
#   >>> Newton(farr, x0)
#   2.954029362747859
#   >>> x1 = 0
#   >>> x2 = -1
#   >>> Newton(farr, x1)
#   0.24544714634084336
#   >>> Newton(farr, x2)
#   -1.193599127316761
#   >>> garr = np.array([2,-8,1,-5,-7,3])
#   >>> n = 5
#   >>> u = 0
#   >>> v = -1
#   >>> itr = 5
#   >>> Bairstow(n,garr,u,v,itr)
#   array([ 0.32745595, -0.77033114])
#   >>>