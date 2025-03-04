sexo = input("seu sexo?") #retorna masulino ou feminino
brasileiro = (input("você é brasileiro?").strip().lower() == "sim")#retorna True ou False
if sexo == "masculino" and brasileiro:
	print("Você é um homem brasileiro")
	print(f"brasileiro: {brasileiro}")
	print("sexo: {}".format(sexo))
if sexo == "feminino" and brasileiro == "sim":
	print("Você é uma mulher brasileira")
if sexo == "masculino" and brasileiro == "não":
	print("Você é um homem estrangeiro")
if sexo == "feminino" and brasileiro == "não":
	print("Você é uma mulher estrangeira")
