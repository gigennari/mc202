import matplotlib.pyplot as plt
import scipy.stats as sci
import numpy
import statistics as st

mT, n, dT, a, da, b, db = 6.5, 100, 0.1, 0.5, 0.2, -0.3, 0.2
if(str(input("Deseja usar valores predefinidos?(s/n): ")) == "n"):
    n = int(input("Insira o número de repetições da medição: "))
    mT = float(input("insira o tempo médio das medições repetidas: ")) 
    dT = float(input("insira o desvio padrão das medições repetidas: "))
    a = float(input("Insira o atraso ou adiantamento médio do operador no início da cronometragem: "))
    da = float(input("Insira o desvio padrão desse atraso ou adiantamento: "))
    b = float(input("Insira o atraso ou adiantamento médio do operador no final da cronometragem: "))
    db = float(input("Insira o desvio padrão desse atraso ou adiantamento: "))


alist = numpy.random.normal(a, da, n)  # gera a lista com os tempos de atraso ou adiantamento do operador no inicio da medição
Tlist = numpy.random.normal(mT, dT, n) # gera a lista com os tempos da medição
blist = []                             
for i in range(n):                     # gera a lista com os tempos de atraso ou adiantamento do operador no final da medição
    blist.append(numpy.random.normal(b+Tlist[i], db))


###Histograma###
plt.figure("Histograma de ocorrências")
#plota os histogramas
plt.hist(Tlist, color="#ffff1a", alpha=0.7)
plt.hist(alist, color="#29ff49", alpha=0.7)
plt.hist(blist, color="#ff4242", alpha=0.7)

plt.xlabel("Tempo (s)")
plt.ylabel("Ocorrências")
plt.title("Histograma de medições repetidas")


###Histograma normalizado###
plt.figure("Histograma normalizado")
#plota os histogramas
plt.hist(Tlist, color="#ffff1a", alpha=0.7,density = True)
plt.hist(alist, color="#29ff49", alpha=0.7, density = True)
plt.hist(blist, color="#ff4242", alpha=0.7, density = True)

#plota as gaussianas
x_Tnormal = numpy.linspace(min(Tlist), max(Tlist),n)
y_Tnormal = sci.norm.pdf(x_Tnormal,mT,dT)
plt.plot(x_Tnormal,y_Tnormal, color="#cccc00", label="Final da queda (f.d.p. gaussiana)" )

x_anormal = numpy.linspace(min(alist), max(alist),n)
y_anormal = sci.norm.pdf(x_anormal,a,da)
plt.plot(x_anormal,y_anormal, color="#009416", label="Início da cronometragem (f.d.p. gaussiana)" )

x_bnormal = numpy.linspace(min(blist), max(blist),n)
y_bnormal = sci.norm.pdf(x_bnormal,b+mT,db)
plt.plot(x_bnormal,y_bnormal, color="#940000", label="Final da cronometragem (f.d.p. gaussiana)" )

plt.xlabel("Tempo (s)")
plt.ylabel("Densidade de ocorrências (1/s)")
plt.title("Histograma de densidade de medições")
plt.legend(loc="upper center")

### T e média progressiva ###
plt.figure("Média progressiva")
plt.scatter(numpy.linspace(0,n,n),Tlist, label="Tempo",s=3)

media_prog = [Tlist[i] for i in range(n)]
for i in range(1,n):
    media_prog[i] = (media_prog[i-1]*(i+1))/(i+2) + media_prog[i]/(i+2)
dT_prog=[0 for i in range(n)]
for i in range(2,n):
    dT_prog[i]=st.stdev([Tlist[j] for j in range(i)])
Tplus = [media_prog[i]+dT_prog[i] for i in range(n)]
Tminus = [media_prog[i]-dT_prog[i] for i in range(n)]
TplusMean = [media_prog[0] for i in range(n)]
TminusMean = [media_prog[0] for i in range(n)]
for i in range(1,n):
    TplusMean[i] = media_prog[i]+dT_prog[i]/numpy.sqrt(i)
    TminusMean[i] = media_prog[i]-dT_prog[i]/numpy.sqrt(i)
plt.fill_between(numpy.linspace(0,n,n), Tminus, Tplus,
    alpha=0.15, edgecolor='grey', facecolor='grey',
    linewidth=0,label = "Desvio padrão progressivo")
plt.fill_between(numpy.linspace(0,n,n), TplusMean, TminusMean,
    alpha=0.5, edgecolor='#3F7F4C', facecolor='#7EFF99',
    linewidth=0,label = "Desvio padrão da média (progressivo)")
plt.plot(media_prog, label="Média progressiva",color="red")
plt.title("Tempos reais")
plt.ylabel("Tempo (s)")
plt.xlabel("Realização")
plt.legend(loc="upper right")


### Tempo medido e média progressiva ###
plt.figure("Tempos medidos")
plt.scatter(numpy.linspace(0,n,n),[blist[i] - alist[i] for i in range(n)], label="Tempo medido",s=3)
tempo_medido = [blist[i] - alist[i] for i in range(n)]
media_medida = [0 for i in range(n)]
media_medida[0] = tempo_medido[0]
for i in range(1,n):
    media_medida[i] = (media_medida[i-1]*(i+1))/(i+2) + tempo_medido[i]/(i+2)
plt.plot(media_medida,label="Média progressiva do tempo medido",color="red")
dT_medido_prog=[0 for i in range(n)]
for i in range(2,n):
    dT_medido_prog[i]=st.stdev([tempo_medido[j] for j in range(i)])
Tm_plus = [media_medida[i]+dT_medido_prog[i] for i in range(n)]
Tm_minus = [media_medida[i]-dT_medido_prog[i] for i in range(n)]
Tm_plusMean = [media_medida[0] for i in range(n)]
Tm_minusMean = [media_medida[0] for i in range(n)]
for i in range(1,n):
    Tm_plusMean[i] = media_medida[i]+dT_medido_prog[i]/numpy.sqrt(i)
    Tm_minusMean[i] = media_medida[i]-dT_medido_prog[i]/numpy.sqrt(i)
plt.fill_between(numpy.linspace(0,n,n), Tm_minus, Tm_plus,
    alpha=0.15, edgecolor='grey', facecolor='grey',
    linewidth=0,label = "Desvio padrão progressivo")
plt.fill_between(numpy.linspace(0,n,n), Tm_plusMean, Tm_minusMean,
    alpha=0.5, edgecolor='#3F7F4C', facecolor='#7EFF99',
    linewidth=0,label = "Desvio padrão da média (progressivo)")
plt.title("Tempos medidos")
plt.ylabel("Tempo (s)")
plt.xlabel("Realização")
plt.legend(loc="upper right")

### Erro sistemático e sua média progressiva ###
plt.figure("Erro sistemático e sua média progressiva")
erro_sistematico = [(blist[i] - alist[i]) - Tlist[i] for i in range(n)]
plt.scatter(numpy.linspace(0,n,n),erro_sistematico, label="Erro sistemático",s=3)
media_erro = [0 for i in range(n)]
media_erro[0] = erro_sistematico[0]
for i in range(1,n):
    media_erro[i] = (media_erro[i-1]*(i+1))/(i+2) + erro_sistematico[i]/(i+2)
plt.plot(media_erro,label="Média progressiva do erro sistemático",color="red")
dErr_prog=[0 for i in range(n)]
for i in range(2,n):
    dErr_prog[i]=st.stdev([erro_sistematico[j] for j in range(i)])
Errplus = [media_erro[i]+dErr_prog[i] for i in range(n)]
Errminus = [media_erro[i]-dErr_prog[i] for i in range(n)]
ErrplusMean = [media_erro[0] for i in range(n)]
ErrminusMean = [media_erro[0] for i in range(n)]
for i in range(1,n):
    ErrplusMean[i] = media_erro[i]+dErr_prog[i]/numpy.sqrt(i)
    ErrminusMean[i] = media_erro[i]-dErr_prog[i]/numpy.sqrt(i)
plt.fill_between(numpy.linspace(0,n,n), Errplus, Errminus,
    alpha=0.15, edgecolor='grey', facecolor='grey',
    linewidth=0,label = "Desvio padrão (progressivo)")
plt.fill_between(numpy.linspace(0,n,n), ErrplusMean, ErrminusMean,
    alpha=0.5, edgecolor='#3F7F4C', facecolor='#7EFF99',
    linewidth=0,label = "Desvio padrão da média (progressivo)")
plt.title("Erro sistemático")
plt.ylabel("T$_m$-T$_r$ (s)")
plt.xlabel("Realização")
plt.legend(loc="upper right")
           
plt.show()
