""" O sinal com tempo de ciclo = T fica verde quando t mod(2T) < T-5, onde t é o tempo atual em segundos.
    Iteramos, portanto pelos 60*60*5 segundos = 18000s e identificamos quando todos os sinais estão verdes.
    Para receber o input, lemos linha a linha até encontrarmos um 0. Para o output, usamos a função tempo_bonito(t)
    para separar horas, minutos e segundos."""

def tempo_bonito(t):
    h = int(t/3600)
    m = int((t%3600)/60)
    s = t%60

    return '{:02}:{:02}:{:02}'.format(h,m,s)

def is_green(T,t):
    return (t%(2*T)) < T-5

def run(sinais):
    first_orange = min(sinais) - 5
    for t in range(first_orange,18001):
        done = True
        for T in sinais:
            if not is_green(T,t):
                done = False
                break
        if done:
            print(tempo_bonito(t))
            return

    print('Signals fail to synchronise in 5 hours')



sinais = []
while True:
    inp = input()
    if inp == '0 0 0':
        break
    sinais += [int(x) for x in inp.split()]

    if sinais[-1] == 0:
        run(sinais[:-1])
        sinais = []

