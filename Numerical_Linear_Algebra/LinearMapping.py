# Nick Michael

def main():
    import numpy as np
    import matplotlib.pyplot as plt
    from matplotlib.animation import FuncAnimation

    mn, mx = -2, 2

    fig = plt.figure()
    ax = fig.add_subplot(1,1,1)

    arr = np.array([[0.0,1.0],
                    [1.0,0.0]])

    N = 100
    t = np.linspace(0,1,N)

    ani = FuncAnimation(fig, m_map, frames=N, fargs=(mn, mx, arr, ax, t), interval=5)

    ax.axis('scaled')
    ax.set_xlim(mn, mx)
    ax.set_ylim(mn, mx)
    plt.show()



def m_axis(mn, mx, ax):
    import numpy as np

    sz = abs(mn) + abs(mx) + 1
    x = np.linspace(mn,mx,sz)
    y = np.linspace(mn,mx,sz)

    MX = np.zeros((sz,sz,2))
    for i in range(sz):
        MX[i,:,0] = x
        MX[i,:,1] = y[i]

    MY = np.zeros((sz,sz,2))
    for i in range(sz):
        MY[i,:,0] = x[i]
        MY[i,:,1] = y

    for i in range(sz):
        if (mn + i == 0):
            ax.plot(MX[i,:,0], MX[i,:,1], color='#d0d000', lw=0.5)
            ax.plot(MY[i,:,0], MY[i,:,1], color='#d0d000', lw=0.5)

        else:
            ax.plot(MX[i,:,0], MX[i,:,1], color='#b0b0b0', lw=0.5)
            ax.plot(MY[i,:,0], MY[i,:,1], color='#b0b0b0', lw=0.5)



def m_map(k, mn, mx, barr, ax, t):
    import numpy as np

    sz = abs(mn) + abs(mx) + 1
    x = np.linspace(mn,mx,sz)
    y = np.linspace(mn,mx,sz)

    arr = np.zeros((2,2))

    arr[0,0] = (barr[0,0]-1)*t[k] + 1
    arr[0,1] = barr[0,1]*t[k]
    arr[1,0] = barr[1,0]*t[k]
    arr[1,1] = (barr[1,1]-1)*t[k] + 1

    MX = np.zeros((sz,sz,2))
    for i in range(sz):
        MX[i,:,0] = x
        MX[i,:,1] = y[i]

    MY = np.zeros((sz,sz,2))
    for i in range(sz):
        MY[i,:,0] = x[i]
        MY[i,:,1] = y

    MPX = np.zeros((sz,sz,2))
    for i in range(sz):
        for j in range(sz):
            MPX[i,j,:] = np.matmul(arr, MX[i,j,:])

    MPY = np.zeros((sz,sz,2))
    for i in range(sz):
        for j in range(sz):
            MPY[i,j,:] = np.matmul(arr, MY[i,j,:])

    ax.clear()
    for i in range(sz):
        if (mn + i == 0):
            ax.plot(MPX[i,:,0], MPX[i,:,1], color='#0000f0', lw=2)
            ax.plot(MPY[i,:,0], MPY[i,:,1], color='#0000f0', lw=2)

        else:
            ax.plot(MPX[i,:,0], MPX[i,:,1], color='#606060', lw=2)
            ax.plot(MPY[i,:,0], MPY[i,:,1], color='#606060', lw=2)

    m_axis(mn, mx, ax)



if __name__=="__main__":
    main()