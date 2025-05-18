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
      <td>22205</td><td>28043</td>
      <td>8492</td><td>8383</td>
      <td>8980</td><td>8790</td>
      <td>7842</td><td>8056</td>
    </tr>
    <tr>
      <td>st70</td>
      <td>3410</td><td>3454</td>
      <td>712</td><td>718</td>
      <td>791</td><td>811</td>
      <td>677</td><td>678</td>
    </tr>
    <tr>
      <td>gil262</td>
      <td>26298</td><td>27213</td>
      <td>2675</td><td>2521</td>
      <td>3021</td><td>2889</td>
      <td>2576</td><td>2504</td>
    </tr>
    <tr>
      <td>gr666</td>
      <td>5554</td><td>8788</td>
      <td>3354</td><td>3339</td>
      <td>3923</td><td>3915</td>
      <td>3192</td><td>3249</td>
    </tr>
    <tr>
      <td>dsj1000</td>
      <td>557633555</td><td>557770011</td>
      <td>20205428</td><td>20281802</td>
      <td>24630960</td><td>23570849</td>
      <td>20327483</td><td>19940298</td>
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
      <td>25605</td><td>–</td>
      <td>15768</td><td>–</td>
      <td>16580</td><td>–</td>
      <td>15578</td><td>–</td>
    </tr>
    <tr>
      <td>t2_berlin52</td>
      <td>23005</td><td>–</td>
      <td>10835</td><td>–</td>
      <td>11780</td><td>–</td>
      <td>10710</td><td>–</td>
    </tr>
    <tr>
      <td>t3_berlin52</td>
      <td>23805</td><td>–</td>
      <td>13062</td><td>–</td>
      <td>14580</td><td>–</td>
      <td>13010</td><td>–</td>
    </tr>
    <tr>
      <td>t1_st70</td>
      <td>3410</td><td>–</td>
      <td>745</td><td>–</td>
      <td>831</td><td>–</td>
      <td>711</td><td>–</td>
    </tr>
    <tr>
      <td>t2_st70</td>
      <td>3410</td><td>–</td>
      <td>791</td><td>–</td>
      <td>911</td><td>–</td>
      <td>782</td><td>–</td>
    </tr>
    <tr>
      <td>t3_st70</td>
      <td>3410</td><td>–</td>
      <td>871</td><td>–</td>
      <td>1019</td><td>–</td>
      <td>867</td><td>–</td>
    </tr>
    <tr>
      <td>t4_st70</td>
      <td>3410</td><td>–</td>
      <td>1128</td><td>–</td>
      <td>1251</td><td>–</td>
      <td>1099</td><td>–</td>
    </tr>
    <tr>
      <td>t1_gil262</td>
      <td>26298</td><td>–</td>
      <td>3539</td><td>–</td>
      <td>4190</td><td>–</td>
      <td>3579</td><td>–</td>
    </tr>
    <tr>
      <td>t2_gil262</td>
      <td>26298</td><td>–</td>
      <td>3293</td><td>–</td>
      <td>3856</td><td>–</td>
      <td>3331</td><td>–</td>
    </tr>
  </tbody>
</table>

## Considerações

- O guloso encontra uma boa rota, comparada à trivial 1, 2, 3, ..., n?

Sim. Comparando a avaliação direta da rota trivial com a que parte da rota gulosa, vemos que o guloso encontra boas rotas, pois obtém resultados bem superiores, reduzindo o custo em 50-60% em média nas instâncias com e sem pedágio.

- Alguma versão do guloso se saiu melhor ou tanto faz?

Tanto faz, pois, apesar de ser possível ver uma versão se sobressaindo em relação à outra para algumas instâncias, na média e em uma vista geral as diferenças foram bem sutis.

- A busca local conseguiu melhorar a solução trivial? Em quanto?

Sim, observando a tabela vemos que claramente tal melhora. Considerando as duas soluções inciais, o aumento foi de 50-70% em média.

- A busca local conseguiu melhorar a solução gulosa? Em quanto? Compensou fazer busca local na solução gulosa em vez da trivial?

Sim. Nota-se que aplicar a busca local na solução construtiva gerada pela heurísica gulosa resultou na redução do custo em torno de 10%. Esse efeito faz sentido, pois a busca local procura por ótimos locais a partir de um ponto mais vantajoso do que começando de um solução simples como a crescente. Dessa forma, compensa fazer essa combinação.

Além disso:
- gil262 e dsj1000 mostram casos onde “two‑sides” supera o “back‑only”, sugerindo que inserir pontos no início ou fim da solução pode ajudar para instâncias maiores.

