import matplotlib.pyplot as plt
import numpy as np
import sys

def regression(x, y):
    mx = x.mean()
    my = y.mean()
    mxy = (x*y).mean()
    mxx = (x*x).mean()
    k = (mx * my - mxy) / (mx ** 2 - mxx)
    b = my - k * mx
    return k, b

def func(x, k, b):
    return k * x + b

def tempreture_year(days):
    tempreture = {}
    for day in days:
        d = []
        if day[3] != 999.9:
            if tempreture.get(day[0]) == None:
                d.append(day[3])
                tempreture[day[0]] = d
            else:
                d = tempreture[day[0]]
                d.append(day[3])
                tempreture[day[0]] = d
    return tempreture
    

def mean_temp(tempreture, g):
    mean_tempreture = {}
    for t in tempreture:
        if(g == 'a'):
            if(len(tempreture[t]) > 330):
                mean_tempreture[t] = np.mean(tempreture[t])
        else:
             mean_tempreture[t] = np.mean(tempreture[t])
    return mean_tempreture


def analyzes_all_mean_tempreture(filename, graph):
    data = []
    with open(filename, 'r') as f:
        for l in f:
            data_d = []
            line = l.split()
            if len(line) > 1:
                data_d.append(int(line[1]))
                data_d.append(int(line[2]))
                data_d.append(int(line[3]))
                data_d.append(int(line[7])/10)
                data.append(data_d)
    
    
    mean_tempreture = mean_temp(tempreture_year(data), graph)
    
    x = np.array([k for k in mean_tempreture.keys()])
    y = np.array([mean_tempreture[i] for i in mean_tempreture])
    
    y1 = []
    k, b = regression(x,y)
    for x1 in x: 
        y1.append(func(x1,k,b))
    
    print('y =', k, '* x', '+', b)
    plt.plot(x,y)
    plt.plot(x, y1)
    plt.show()


def analizes_all_summer_winter_mean_tempreture(filename, graph):
    data_summer = []
    data_winter = []
    with open(filename, 'r') as f:
        for l in f:
            data_d = []
            line = l.split()
            if len(line) > 1:
                
                data_d.append(int(line[1]))
                data_d.append(int(line[2]))
                data_d.append(int(line[3]))
                data_d.append(int(line[7])/10)
                if line[2] == '6' or line[2] == '7' or line[2] == '8':
                    data_summer.append(data_d)
                elif line[2] == '12' or line[2] == '2' or line[2] == '1':
                    data_winter.append(data_d)

    mean_tempreture_summer = mean_temp(tempreture_year(data_summer),graph)
    #print(len(mean_tempreture_summer))

    mean_tempreture_winter = mean_temp(tempreture_year(data_winter), graph)
    
    x_summer = np.array([k for k in mean_tempreture_summer.keys()])
    y_summer = np.array([mean_tempreture_summer[i] for i in mean_tempreture_summer])
    x_winter = np.array([k for k in mean_tempreture_winter.keys()])
    y_winter = np.array([mean_tempreture_winter[i] for i in mean_tempreture_winter])
    plt.plot(x_summer, y_summer)
    plt.plot(x_winter, y_winter)
    plt.show()

path = sys.argv[1]
graphik = sys.argv[2]
if graphik == 'a':
    analyzes_all_mean_tempreture(path, graphik)
elif graphik == 'p':
    analizes_all_summer_winter_mean_tempreture(path, graphik)
exit()

