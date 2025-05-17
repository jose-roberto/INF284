parte_0 = {
    "burma14": {
        "crescente": 42,
        "impar_par": 60
    },
    "berlin52": {
        "crescente": 22205,
        "impar_par": 28043
    },
    "st70": {
        "crescente": 3410,
        "impar_par": 3454
    },
    "gil262": {
        "crescente": 26298,
        "impar_par": 27213
    },
    "gr666": {
        "crescente": 5554,
        "impar_par": 8788
    },
    "dsj1000": {
        "crescente": 557633555,
        "impar_par": 557770011
    },
    "t1_burma14": {
        "crescente": 45,
    },
    "t2_burma14": {
        "crescente": 43
    },
    "t3_burma14": {
        "crescente": 44,
    },
    "t1_berlin52": {
        "crescente": 25605
    },
    "t2_berlin52": {
        "crescente": 23005
    },
    "t3_berlin52": {
        "crescente": 23805
    },
    "t1_st70": {
        "crescente": 3410
    },
    "t2_st70": {
        "crescente": 3410
    },
    "t3_st70": {
        "crescente": 3410
    },
    "t4_st70": {
        "crescente": 3410
    },
    "t1_gil262": {
        "crescente": 26298
    },
    "t2_gil262": {
        "crescente": 26298
    }
}

parte_1 = {
    "burma14": {
        "crescente": 31,
        "impar_par": 30
    },
    "berlin52": {
        "crescente": 8492,
        "impar_par": 8383
    },
    "st70": {
        "crescente": 712,
        "impar_par": 718
    },
    "gil262": {
        "crescente": 2675,
        "impar_par": 2521
    },
    "gr666": {
        "crescente": 3354,
        "impar_par": 3339
    },
    "dsj1000": {
        "crescente": 20205428,
        "impar_par": 20281802
    },
    "t1_burma14": {
        "crescente": 38
    },
    "t2_burma14": {
        "crescente": 36
    },
    "t3_burma14": {
        "crescente": 39
    },
    "t1_berlin52": {
        "crescente": 15768
    },
    "t2_berlin52": {
        "crescente": 10835
    },
    "t3_berlin52": {
        "crescente": 13062
    },
    "t1_st70": {
        "crescente": 745
    },
    "t2_st70": {
        "crescente": 791
    },
    "t3_st70": {
        "crescente": 871
    },
    "t4_st70": {
        "crescente": 1128
    },
    "t1_gil262": {
        "crescente": 3539
    },
    "t2_gil262": {
        "crescente": 3293
    }
}

parte_2 = {
    "burma14": {
        "avaliacao_direta_nearest_neighbor": 31,
        "avaliacao_direta_nearest_neighbor_two_sides": 34,
        "busca_local_nearest_neighbor": 30,
        "busca_local_nearest_neighbor_two_sides": 30
    },
    "berlin52": {
        "avaliacao_direta_nearest_neighbor": 8980,
        "avaliacao_direta_nearest_neighbor_two_sides": 8790,
        "busca_local_nearest_neighbor": 7842,
        "busca_local_nearest_neighbor_two_sides": 8056
    },
    "st70": {
        "avaliacao_direta_nearest_neighbor": 791,
        "avaliacao_direta_nearest_neighbor_two_sides": 811,
        "busca_local_nearest_neighbor": 677,
        "busca_local_nearest_neighbor_two_sides": 678
    },
    "gil262": {
        "avaliacao_direta_nearest_neighbor": 3021,
        "avaliacao_direta_nearest_neighbor_two_sides": 2889,
        "busca_local_nearest_neighbor": 2576,
        "busca_local_nearest_neighbor_two_sides": 2504
    },
    "gr666": {
        "avaliacao_direta_nearest_neighbor": 3923,
        "avaliacao_direta_nearest_neighbor_two_sides": 3915,
        "busca_local_nearest_neighbor": 3192,
        "busca_local_nearest_neighbor_two_sides": 3249
    },
    "dsj1000": {
        "avaliacao_direta_nearest_neighbor": 24630960,
        "avaliacao_direta_nearest_neighbor_two_sides": 23570849,
        "busca_local_nearest_neighbor": 20327483,
        "busca_local_nearest_neighbor_two_sides": 19940298
    },
    "t1_burma14": {
        "avaliacao_direta_nearest_neighbor": 38,
        "busca_local_nearest_neighbor": 38
    },
    "t2_burma14": {
        "avaliacao_direta_nearest_neighbor": 36,
        "busca_local_nearest_neighbor": 36
    },
    "t3_burma14": {
        "avaliacao_direta_nearest_neighbor": 41,
        "busca_local_nearest_neighbor": 36
    },
    "t1_berlin52": {
        "avaliacao_direta_nearest_neighbor": 16580,
        "busca_local_nearest_neighbor": 15578
    },
    "t2_berlin52": {
        "avaliacao_direta_nearest_neighbor": 11780,
        "busca_local_nearest_neighbor": 10710
    },
    "t3_berlin52": {
        "avaliacao_direta_nearest_neighbor": 14580,
        "busca_local_nearest_neighbor": 13010
    },
    "t1_st70": {
        "avaliacao_direta_nearest_neighbor": 831,
        "busca_local_nearest_neighbor": 711
    },
    "t2_st70": {
        "avaliacao_direta_nearest_neighbor": 911,
        "busca_local_nearest_neighbor": 782
    },
    "t3_st70": {
        "avaliacao_direta_nearest_neighbor": 1019,
        "busca_local_nearest_neighbor": 867
    },
    "t4_st70": {
        "avaliacao_direta_nearest_neighbor": 1251,
        "busca_local_nearest_neighbor": 1099
    },
    "t1_gil262": {
        "avaliacao_direta_nearest_neighbor": 4190,
        "busca_local_nearest_neighbor": 3579
    },
    "t2_gil262": {
        "avaliacao_direta_nearest_neighbor": 3856,
        "busca_local_nearest_neighbor": 3331
    }
}

def diferenca_percentual(d1, chave1, d2=None, chave2=None):
    if d2 is None:
        d2 = d1
    if chave2 is None:
        chave2 = chave1

    resultados = {}
    for inst, vals1 in d1.items():
        vals2 = d2.get(inst, {})

        a = vals1.get(chave1)
        b = vals2.get(chave2)

        if a is None or b is None:
            resultados[inst] = None
        elif a == 0:
            resultados[inst] = None
        else:
            resultados[inst] = round((b - a) / a * 100, 2)
    return resultados

def calcular_media(valores):
    valores_validos = [diff for diff in valores if diff is not None]
    if valores_validos:
        return round(sum(valores_validos) / len(valores_validos), 2)
    else:
        return "N/A"

# Questão 1
print("Questão 1")
resultado = diferenca_percentual(parte_0, "crescente", parte_2, "avaliacao_direta_nearest_neighbor")
print("Diferença percentual entre 'crescente' e 'avaliacao_direta_nearest_neighbor' - Parte 0 e 2:")
for inst, diff in resultado.items():
    print(f"{inst}: {diff}%")
print("Média: ", calcular_media(resultado.values()))

resultado = diferenca_percentual(parte_0, "crescente", parte_2, "avaliacao_direta_nearest_neighbor_two_sides")
print("\nDiferença percentual entre 'crescente' e 'avaliacao_direta_nearest_neighbor_two_sides' - Parte 0 e 2:")
for inst, diff in resultado.items():
    print(f"{inst}: {diff}%")
print("Média: ", calcular_media(resultado.values()))

# Questão 2
print("\nQuestão 2")
resultado = diferenca_percentual(parte_2, "avaliacao_direta_nearest_neighbor", parte_2, "avaliacao_direta_nearest_neighbor_two_sides")
print("Diferença percentual entre 'avaliacao_direta_nearest_neighbor' e 'avaliacao_direta_nearest_neighbor_two_sides' - Parte 2:")
for inst, diff in resultado.items():
    print(f"{inst}: {diff}%")
print("Média: ", calcular_media(resultado.values()))

resultado = diferenca_percentual(parte_2, "busca_local_nearest_neighbor", parte_2, "busca_local_nearest_neighbor_two_sides")
print("\nDiferença percentual entre 'busca_local_nearest_neighbor' e 'busca_local_nearest_neighbor_two_sides' - Parte 2:")
for inst, diff in resultado.items():
    print(f"{inst}: {diff}%")
print("Média: ", calcular_media(resultado.values()))

# resultado = diferenca_percentual(parte_2, "avaliacao_direta_nearest_neighbor", parte_2, "busca_local_nearest_neighbor")
# print("\nDiferença percentual entre 'avaliacao_direta_nearest_neighbor' e 'busca_local_nearest_neighbor' - Parte 2:")
# for inst, diff in resultado.items():
#     print(f"{inst}: {diff}%")
# print("Média: ", calcular_media(resultado.values()))

# resultado = diferenca_percentual(parte_2, "avaliacao_direta_nearest_neighbor_two_sides", parte_2, "busca_local_nearest_neighbor_two_sides")
# print("\nDiferença percentual entre 'avaliacao_direta_nearest_neighbor_two_sides' e 'busca_local_nearest_neighbor_two_sides' - Parte 2:")
# for inst, diff in resultado.items():
#     print(f"{inst}: {diff}%")
# print("Média: ", calcular_media(resultado.values()))

# Questão 3
print("\nQuestão 3")
resultado = diferenca_percentual(parte_0, "crescente", parte_1, "crescente")
print("Diferença percentual entre 'crescente' e 'crescente' - Parte 0 e 1:")
for inst, diff in resultado.items():
    print(f"{inst}: {diff}%")
print("Média: ", calcular_media(resultado.values()))

resultado = diferenca_percentual(parte_0, "impar_par", parte_1, "impar_par")
print("\nDiferença percentual entre 'impar_par' e 'impar_par' - Parte 0 e 1:")
for inst, diff in resultado.items():
    print(f"{inst}: {diff}%")
print("Média: ", calcular_media(resultado.values()))

# Questões 4 e 5
print("\nQuestão 4 e 5")
resultado = diferenca_percentual(parte_2, "avaliacao_direta_nearest_neighbor", parte_2, "busca_local_nearest_neighbor")
print("Diferença percentual entre 'avaliacao_direta_nearest_neighbor' e 'busca_local_nearest_neighbor' - Parte 2:")
for inst, diff in resultado.items():    
    print(f"{inst}: {diff}%")
print("Média: ", calcular_media(resultado.values()))

resultado = diferenca_percentual(parte_2, "avaliacao_direta_nearest_neighbor_two_sides", parte_2, "busca_local_nearest_neighbor_two_sides")
print("\nDiferença percentual entre 'avaliacao_direta_nearest_neighbor_two_sides' e 'busca_local_nearest_neighbor_two_sides' - Parte 2:")
for inst, diff in resultado.items():
    print(f"{inst}: {diff}%")
print("Média: ", calcular_media(resultado.values()))

