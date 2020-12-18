import csv
import numpy as np
import matplotlib.pyplot as plt

import csv

def read_route():
    route = str(input())
    tour = []
    edge = []
    for city in route.split(','):
        if(city != '\r'):
            edge.append(int(city))
            if(len(edge) == 2):
                tour.append(edge.copy())
                edge.pop(0)
    edge.append(int(route.split(',')[0]))
    tour.append(edge.copy())
    return list(tour)


def route_csv(route, coord_filename, route_filename, id_coord_start = 1):
    '''
    Cria um arquivo csv de rotas. O cabecalho do arquivo criado sera 
    x_i, y_i, x_j e y_j sendo i a coordenada de saida e j a coordenada
    de entrada

    Parametros
    ----------
        route : list([(int) i, (int) j])
            lista de rotas. Cada elemento da lista sera composto por dois interos
            sendo uma coordenada de saida e outra de entrada, ex: [[3,0], [0, 4], ...]
        coord_filename : str
            Arquivo csv que tem as coordenadas (id, x, y). Estes arquivos com as coordenadas
            estao na pasta '/data/coord'
        route_filename : str
            Arquivo csv que sera criado para armazenar as rotas
        id_coord_start : int
            Indice da coordenada de inicio
    '''

    coord = dict()

    with open(coord_filename, 'r', encoding='utf-8') as coord_file:
        
        reader = csv.DictReader(coord_file)
        coord = {row['id'] : {'x': row['x'], 'y': row['y']} for row in reader}

    with open(route_filename, 'w') as csv_file:
        
        writer = csv.DictWriter(csv_file, fieldnames=['x_i', 'y_i', 'x_j', 'y_j'])
        writer.writeheader()

        for r in route:
            writer.writerow({'x_i': coord[str(r[0] + id_coord_start)]['x'],
                             'y_i': coord[str(r[0] + id_coord_start)]['y'],
                             'x_j': coord[str(r[1] + id_coord_start)]['x'],
                             'y_j': coord[str(r[1] + id_coord_start)]['y']})
        
     
        
def plot(route_filename, img_filename, background=False, background_img='./images/backgrounds/galaxy_image.jpg', background_extent=[0, 1920, 0, 1080]):
    '''
    Cria um plot da rota (minima) que passa por todas as coordenadas.
    As informacoes deste plot veem de um arquivo csv com as rotas e plota
    uma imagem (img_name)

    Parametros
    ----------
        route_filename : str
            arquivo csv com as rotas. O cabecalho do arquivo csv eh
            x_i, y_i, x_j e y_j sendo i a coordenada de saida e j a
            coordenada de entrada
        img_name : str
            nome do arquivo de plot
        background : bool
            flag que indica se o plot vai ter uma image de fundo
            (background=True) ou nao (background=False). Por padrao
            background=False
        background_img : str
            Arquivo (Image) de background para o plot
        background_extent : list(int)
            Lista de 4 inteiros que indicarao a extensao da imagem de background 
            do plot. Por padrao as suas coordenadas sao [x0, x1, y0, y1]
    '''

    with open(route_filename, 'r') as route_file:

        reader = list(csv.DictReader(route_file))

        line_color = 'black'

        if background:
            img = plt.imread(background_img)
            plt.imshow(img, extent=background_extent)
            line_color = 'white'

        for row in reader:
            plt.plot([float(row['x_i']), float(row['x_j'])], 
                     [float(row['y_i']), float(row['y_j'])], 
                      '--', lw = 3, color = line_color)

        for row in reader:
            plt.plot(float(row['x_i']), float(row['y_i']), marker = '*', ms = 5, color = 'red')
        
        plt.axis('off')

        plt.savefig(img_filename, transparent=True)

route_csv(read_route(), '../coord/test30.csv', '../output/test1.csv')
# plot('../output/test1.csv', 'plot')