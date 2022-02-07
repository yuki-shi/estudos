import requests
import sys

# API: https://openweathermap.org/api

API_KEY = '9d04ff20fee3dd2536ac47ee01db8a8e'
BASE_URL = 'https://api.openweathermap.org/data/2.5/weather'

def main():
    checkArgv()
    city = getCity()
    request_url = f'{BASE_URL}?appid={API_KEY}&q={city}'
    response = requests.get(request_url) # retornará um .json

    if response.status_code == 200:     # logo, se o request tiver dado certo
        data = response.json()
        weather = data['weather'][0]['description']
        temperature = round(data['main']['temp'] - 273.15)
        print(f'Weather: {weather}')
        print(f'Temperature: {temperature}°C')

    else:
        print('Incorrect city name')



def getCity():
    if len([letter for letter in sys.argv[1] if letter.isalpha()]) == len(sys.argv[1]):
        return sys.argv[1]
    else:
        sys.exit('yuk')
        

def checkArgv():
    if len(sys.argv) == 2:
        return
    else:
        sys.exit('Correct usage: ./weather.py city_name')


if __name__ == '__main__':
    main()