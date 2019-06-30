# Nick Michael

from pyqtgraph.Qt import QtGui, QtCore
import numpy as np
import pyqtgraph as pg
import sys

class Plot2D():
    def __init__(self):
        self.traces = dict()

        pg.setConfigOption('background', '#171717')
        pg.setConfigOption('foreground', '#b0b0b0')

        self.app = QtGui.QApplication([])

        self.win = pg.GraphicsWindow(title="Basic plotting examples")
        self.win.resize(1000,1000)
        self.win.setWindowTitle('pyqtgraph example: Plotting')

        pg.setConfigOptions(antialias=True)

        self.canvas = self.win.addPlot(title="Pytelemetry")

    def start(self):
       if (sys.flags.interactive != 1) or not hasattr(QtCore, 'PYQT_VERSION'):
            QtGui.QApplication.instance().exec_()

    def trace(self,name,dataset_x,dataset_y):
        if name in self.traces:
            self.traces[name].setData(dataset_x,dataset_y)
        else:
            #self.traces[name] = self.canvas.plot(pen='#b0b0b0')
            self.traces[name] = self.canvas.plot(pen='#12827a')

## Start Qt event loop unless running in interactive mode or using pyside.
if __name__ == '__main__':
    p = Plot2D()
    i = 0
    mn, mx = -25, 25
    sz = abs(mn) + abs(mx) + 1
    x_names = np.linspace(0,sz-1,sz)
    y_names = np.linspace(0,sz-1,sz)

    def update():
        global p, i, mn, mx, sz, x_names, y_names
        N = 250

        x = np.linspace(mn,mx,sz)
        y = np.linspace(mn,mx,sz)

        barr = np.array([[0.0,1.0],
                        [1.0,0.0]])

        t = np.linspace(0,1,N)

        arr = np.zeros((2,2))
        arr[0,0] = (barr[0,0]-1)*t[i] + 1
        arr[0,1] = barr[0,1]*t[i]
        arr[1,0] = barr[1,0]*t[i]
        arr[1,1] = (barr[1,1]-1)*t[i] + 1

        MX = np.zeros((sz,sz,2))
        for k in range(sz):
            MX[k,:,0] = x
            MX[k,:,1] = y[k]

        MY = np.zeros((sz,sz,2))
        for k in range(sz):
            MY[k,:,0] = x[k]
            MY[k,:,1] = y

        MPX = np.zeros((sz,sz,2))
        for k in range(sz):
            for j in range(sz):
                MPX[k,j,:] = np.matmul(arr, MX[k,j,:])

        MPY = np.zeros((sz,sz,2))
        for k in range(sz):
            for j in range(sz):
                MPY[k,j,:] = np.matmul(arr, MY[k,j,:])

        for k in range(sz):
            p.trace('x' + str(x_names[k]), MPX[k,:,0], MPX[k,:,1])
            p.trace('y' + str(y_names[k]), MPY[k,:,0], MPY[k,:,1])
        
        if (t[i] < 1):
            i += 1

        else:
            i = 0

    timer = QtCore.QTimer()
    timer.timeout.connect(update)
    timer.start(60)

p.start()