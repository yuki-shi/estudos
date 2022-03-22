### INICIALIZANDO ###

import pandas as pd

df = pd.read_csv('pokemon_data.csv')

# tsv -> .read_csv('nome/url', sep='\t')
# .read_excel() entre outros tb existe!
# age como reader da biblioteca csv



### LEITURA DE DADOS ###

df.columns # retorna o header em uma lista

df['Name'] # retorna a coluna especificada

df[['Name', 'Type 1']] # retorna uma lista com as colunas

for index, row in df.iterrows(): # itera cada row
    print(index, row['Name'])

df['Type1'].value_counts() # conta a qtd de cada valor em uma coluna

df['Type1'].value_counts(normalize=True) # retorna a %



### FILTERING ###

df.iloc[1:4] # integer locaition: retorna rows 1 ~ 4

df.iloc[2,1] # retorna [row, column] específico

df.loc[df['Type 1'] == 'Fire'] # label: outro modo de realizar query

df.loc[(df['Type 1'] == 'Ghost') & (df['Type 2'] == 'Poison')]  # múltiplas condicionais

df.loc[(df['Type 1'] == 'Ghost') | (df['Type 2'] == 'Poison')] 

df.query('Type 1' != 'Fire') # terceiro método

df[df['Name'].str.contains(pat='chu')] # é possível utilizar métodos de str com .str
#            .str.contains(pat='[a-z]chu', regex=True)


### SORTING / DESCRIBING ###

df.describe() # retorna informações gerais

df.sort_values('Name', ascending=False) # nome, ordem decrescente

df.sort_values(['Type 1', 'HP'], ascending=[1,0]) # múltiplos, [true, false]



### MAKING CHANGES ###

df['Total'] = df.iloc[:, 4:10].sum(axis=1)    # [all rows, columns 4~9] // axis=1 é somar horizontalmente
# df = df.drop(columns=['Total'])    # exclui coluna/row especificado



### INDEXING ###

df.index

df.set_index('Type 1', inplace=True) # inplace retifica a mudança no dataFrame

df.reset_index(inplace=True)

# pd.read_csv('url', index_col='indexCol') -> é possível já inicializar a dataFrame com index definido



### SAVING ###

df.to_csv('pokeminho.csv', index=False)  # como .read_csv, possui suas variações 
#                        parâmetro opcional: remove o index, a primeira coluna


### GROUPING AND AGGREGATING ###
# split - apply function - combine results

df.groupby(['Type 1', 'Type 2'])

df.groupby('Type 1').sum()  # após agrupar, aplicar método agregador

df.groupby('Type 1').max()  # retorna valor máximo por coluna

df.groupby('Type 1')['Attack'].mean()

df.groupby('Type 1').get_group('Ghost') # retorna df específico de um grupo
#       age como SELECT * FROM xxx GROUP BY yyyy

df.groupby('Type 1')['Attack'].agg(['mean', 'min', 'max'])



# APPLYING FUNCTIONS ###

df.groupby('Type 1').apply(lambda x: x.str.contains('Ghost').sum())
df.applymap(lambda x: x.capitalize() if isinstance (x, int) else x) # aplica para todo o df
df[['Speed', 'Attack']].corr() # checa coeficiente de relacionamento entre duas variaveis numericas
