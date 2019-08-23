# Usar datetime do python facilita bastante essa questão, de resto,
# Apenas formatação de input e output

from datetime import datetime as dt
from datetime import timedelta

TC = int(input())

signs = {
	'aquarius': {'start': (1,21), 'end': (2,19)},
	'pisces': {'start': (2,20), 'end': (3,20)},
	'aries': {'start': (3,21), 'end': (4,20)},
	'taurus': {'start': (4,21), 'end': (5,21)},
	'gemini': {'start': (5,22), 'end': (6,21)},
	'cancer': {'start': (6,22), 'end': (7,22)},
	'leo': {'start': (7,23), 'end': (8,21)},
	'virgo': {'start': (8,22), 'end': (9,23)},
	'libra': {'start': (9,24), 'end': (10,23)},
	'scorpio': {'start': (10,24), 'end': (11,22)},
	'sagittarius': {'start': (11,23), 'end': (12,22)},
	#'capricorn': {'start': (12,23), 'end': (1,20)}
	}

for i in range(1,TC+1):
	date = dt.strptime(input(), "%m%d%Y") + timedelta(weeks=40)
	
	crc_sign = 'capricorn'
	for sign in signs:
		if (date.month,date.day) >= signs[sign]['start'] and (date.month,date.day) <= signs[sign]['end']:
			crc_sign = sign
			break

	print(i,date.strftime("%m/%d/")+"{:04}".format(date.year),crc_sign)

