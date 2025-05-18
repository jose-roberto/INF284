<!--
# INF284
Repositório para acompanhar a disciplina INF284 - Metaheurísticas
-->

# Trabalho 1 - Relatório

O trabalho teve como foco a aplicação de heurísticas gulosas e de busca local ao *Traveling Salesman Problem* com limite de pedágios gratuitos. A busca local foi baseada no movimento **2‑opt** combinado com a estratégia **Best Improvement**, enquanto as heurísticas gulosas adotaram os métodos **Nearest Neighbor Back-only** e **Nearest Neighbor Two Sides**.


## Tabela com resultados

<table>
  <thead>
    <tr>
      <th rowspan="3">Instância</th>
      <th colspan="2">Parte 0 -<br>Preliminar</th>
      <th colspan="2">Parte 1 -<br>Busca Local</th>
      <th colspan="4">Parte 2 – Nearest Neighbor</th>
    </tr>
    <tr>
      <th rowspan="2">Crescente</th>
      <th rowspan="2">Ímpar/par</th>
      <th rowspan="2">Crescente</th>
      <th rowspan="2">Ímpar/par</th>
      <th colspan="2">Direta</th>
      <th colspan="2">Busca Local</th>
    </tr>
    <tr>
      <th>NN Back‑only</th>
      <th>NN Two Sides</th>
      <th>NN Back‑only</th>
      <th>NN Two Sides</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>burma14</td>
      <td>42</td><td>60</td>
      <td>31</td><td>30</td>
      <td>31</td><td>34</td>
      <td>30</td><td>30</td>
    </tr>
    <tr>
      <td>berlin52</td>
      <td>22.205</td><td>28.043</td>
      <td>8.492</td><td>8.383</td>
      <td>8.980</td><td>8.790</td>
      <td>7.842</td><td>8.056</td>
    </tr>
    <tr>
      <td>st70</td>
      <td>3.410</td><td>3.454</td>
      <td>712</td><td>718</td>
      <td>791</td><td>811</td>
      <td>677</td><td>678</td>
    </tr>
    <tr>
      <td>gil262</td>
      <td>26.298</td><td>27.213</td>
      <td>2.675</td><td>2.521</td>
      <td>3.021</td><td>2.889</td>
      <td>2.576</td><td>2.504</td>
    </tr>
    <tr>
      <td>gr666</td>
      <td>5.554</td><td>8.788</td>
      <td>3.354</td><td>3.339</td>
      <td>3.923</td><td>3.915</td>
      <td>3.192</td><td>3.249</td>
    </tr>
    <tr>
      <td>dsj1000</td>
      <td>557.633.555</td><td>557.770.011</td>
      <td>20.205.428</td><td>20.281.802</td>
      <td>24.630.960</td><td>23.570.849</td>
      <td>20.327.483</td><td>19.940.298</td>
    </tr>
    <tr>
      <td>t1_burma14</td>
      <td>45</td><td>–</td>
      <td>38</td><td>–</td>
      <td>38</td><td>–</td>
      <td>38</td><td>–</td>
    </tr>
    <tr>
      <td>t2_burma14</td>
      <td>43</td><td>–</td>
      <td>36</td><td>–</td>
      <td>36</td><td>–</td>
      <td>36</td><td>–</td>
    </tr>
    <tr>
      <td>t3_burma14</td>
      <td>44</td><td>–</td>
      <td>39</td><td>–</td>
      <td>41</td><td>–</td>
      <td>36</td><td>–</td>
    </tr>
    <tr>
      <td>t1_berlin52</td>
      <td>25.605</td><td>–</td>
      <td>15.768</td><td>–</td>
      <td>16.580</td><td>–</td>
      <td>15.578</td><td>–</td>
    </tr>
    <tr>
      <td>t2_berlin52</td>
      <td>23.005</td><td>–</td>
      <td>10.835</td><td>–</td>
      <td>11.780</td><td>–</td>
      <td>10.710</td><td>–</td>
    </tr>
    <tr>
      <td>t3_berlin52</td>
      <td>23.805</td><td>–</td>
      <td>13.062</td><td>–</td>
      <td>14.580</td><td>–</td>
      <td>13.010</td><td>–</td>
    </tr>
    <tr>
      <td>t1_st70</td>
      <td>3.410</td><td>–</td>
      <td>745</td><td>–</td>
      <td>831</td><td>–</td>
      <td>711</td><td>–</td>
    </tr>
    <tr>
      <td>t2_st70</td>
      <td>3.410</td><td>–</td>
      <td>791</td><td>–</td>
      <td>911</td><td>–</td>
      <td>782</td><td>–</td>
    </tr>
    <tr>
      <td>t3_st70</td>
      <td>3.410</td><td>–</td>
      <td>871</td><td>–</td>
      <td>1.019</td><td>–</td>
      <td>867</td><td>–</td>
    </tr>
    <tr>
      <td>t4_st70</td>
      <td>3.410</td><td>–</td>
      <td>1.128</td><td>–</td>
      <td>1.251</td><td>–</td>
      <td>1.099</td><td>–</td>
    </tr>
    <tr>
      <td>t1_gil262</td>
      <td>26.298</td><td>–</td>
      <td>3.539</td><td>–</td>
      <td>4.190</td><td>–</td>
      <td>3.579</td><td>–</td>
    </tr>
    <tr>
      <td>t2_gil262</td>
      <td>26.298</td><td>–</td>
      <td>3.293</td><td>–</td>
      <td>3.856</td><td>–</td>
      <td>3.331</td><td>–</td>
    </tr>
  </tbody>
</table>

## Considerações

- O guloso encontra uma boa rota, comparada à trivial 1, 2, 3, ..., n?

Sim. Comparando a avaliação direta da rota trivial com a que parte da rota gulosa, vemos que o guloso encontra boas rotas, pois obtém resultados bem superiores, reduzindo o custo em 50-60% em média nas instâncias com e sem pedágio.

- Alguma versão do guloso se saiu melhor ou tanto faz?

Tanto faz, pois, embora a segunda versão tenha se destacado em instâncias como gil262 (-4,37%) e dsj1000 (-4,3%), a diferença média entre as estratégias foi bem sútil, indicando desempenho equivalente na maioria dos casos.

- A busca local conseguiu melhorar a solução trivial? Em quanto?

Sim, observando a tabela, vemos que claramente tal melhora. Considerando as duas soluções iniciais, o aumento foi de 50-70% em média.

- A busca local conseguiu melhorar a solução gulosa? Em quanto? Compensou fazer busca local na solução gulosa em vez da trivial?

Sim. Nota-se que aplicar a busca local na solução construtiva gerada pela heurística gulosa resultou na redução do custo em torno de 11-14%. Esse efeito faz sentido, pois a busca local procura por ótimos locais a partir de um ponto mais vantajoso do que começando de uma solução simples como a crescente. Dessa forma, compensa fazer essa combinação.

- Além disso:

Em instâncias maiores, como dsj1000, a estratégia Two Sides reduziu o custo em 4,3% em comparação ao Back-only, sugerindo que a flexibilidade de inserção em ambas as extremidades é vantajosa para problemas complexos.
