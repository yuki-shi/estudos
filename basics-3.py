import streamlit as st
import pandas as pd
import plotly.express as px

# Agora pensamos em containers:

header = st.container()
dataset = st.container()
inputs = st.container()
plotplot = st.container()

# Para usar os containers:

with header:
    st.title('YUKI!')
    st.write(''' ###### (tuki)''')

with dataset:
    st.header('Pokeminhos')

    df_pokemon = pd.read_csv('https://gist.githubusercontent.com/armgilles/194bcff35001e7eb53a2a8b441e8b2c6/raw/92200bc0a673d5ce2110aaad4544ed6c4010f687/pokemon.csv')
    st.write(df_pokemon.head())

    st.subheader('T i p o s :')
    ptype = pd.DataFrame(df_pokemon['Type 1'].value_counts())
    st.bar_chart(ptype)

with inputs:
    st.header('monstro bolso')
    
    # Pode-se usar colunas para estilizar:

    sel_col, disp_col = st.columns(2)

    yki = sel_col.slider('yuki', min_value=1, max_value=10, step=1)
    yuki= sel_col.selectbox('aaaa', ['y', 'u', 'k', 'i'])
    yuuki = sel_col.text_input('aqui:', 'yuki')

    disp_col.write(f'{yuuki} tem {yki} dedos')

with plotplot:
    st.header('plotly é legal')

    yuuuki = st.selectbox('T I P O', ['Bug', 'Dark', 'Ghost'])

    df_f = df_pokemon[(df_pokemon['Type 1'] == yuuuki) & (df_pokemon['Generation'] == 3)]

    # Plotagem dinâmica
    fig = px.scatter(
        df_f,
        x='HP',
        y='Name'
    )

    st.plotly_chart(fig)