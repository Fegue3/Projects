import time
import random

# SuperClasses!
class Player:
    def __init__(self):
        pass

    pontos_vida = 100
    pontos_speed = 0
    pontos_mana = 0
    pontos_atk = 0
    pontos_def = 0
    money = 20
    wisdom = 0
    weaponry = 0
    armory = 0
    casa_jogo = 0
    inventario = []
    nome = ""

    def attack(self, opponent):
        dano = ((self.pontos_mana * self.pontos_atk * self.pontos_speed * ((100 + self.wisdom) / 100) * ((100 + self.weaponry) / 100)) -
                (opponent.pontos_mana * opponent.pontos_def * opponent.pontos_speed * ((100 + opponent.wisdom) / 100) * ((100 + opponent.armory) / 100))) * 0.01
        dano = round(dano, 1)

        if dano < 0:
            dano = 0.0

        opponent.pontos_vida -= dano
        opponent.pontos_vida = round(opponent.pontos_vida, 1)

        print(f"O {opponent.nome} sofreu {dano} de dano e tem {opponent.pontos_vida} pontos de vida.")

    def battle(self, opponent):
        global a, b

        a = round(self.pontos_vida, 1)
        b = round(opponent.pontos_vida, 1)

        count = 1

        while self.pontos_vida >= a / 2 and opponent.pontos_vida >= b / 2:
            print(f"Turno {count}:")

            self.attack(opponent)

            print(f"{self.nome}: {self.pontos_vida} pontos de vida, {a}")
            print(f"{opponent.nome}: {opponent.pontos_vida} pontos de vida, {b}")

            if opponent.pontos_vida < b / 2:
                break

            time.sleep(5)

            opponent.attack(self)

            print(f"{self.nome}: {self.pontos_vida} pontos de vida, {a}")
            print(f"{opponent.nome}: {opponent.pontos_vida} pontos de vida, {b}")
            print()

            count += 1

        if self.pontos_vida < a / 2:
            print(f"\n{opponent.nome} ganhou a batalha!")
            opponent.money = round(opponent.money + self.money * 0.4, 0)
            self.money = round(self.money * 0.6, 0)
            opponent.wisdom += 2
            self.wisdom += 1

            print(f"{opponent.nome} tem agora {opponent.money} coins.")
            print(f"{self.nome} tem agora {self.money} coins.")

        if opponent.pontos_vida < b / 2:
            print(f"\n{self.nome} ganhou a batalha!")
            self.money = round(self.money + opponent.money * 0.4, 0)
            opponent.money = round(opponent.money * 0.6, 0)
            self.wisdom += 2
            opponent.wisdom += 1

            print(f"{opponent.nome} tem agora {opponent.money} coins.")
            print(f"{self.nome} tem agora {self.money} coins.")

    def buy(self):
        item = ""
        while item not in [i for i in items.keys()]:
            print("\nEscolha apenas uma das opções da lista, por favor")
            item_possibilities = ', '.join([f"{i}: {items[i]['preço']}" for i in items.keys()])
            item = input(f"Que item queres comprar? Possibilidades: {item_possibilities}\n")

        if items[item]["preço"] <= self.money:
            self.money -= items[item]["preço"]
            self.inventario.append(item)
            print(f"O {self.nome} comprou uma unidade de {item}")
        else:
            print(f"Seu pobre! Não vendemos fiado, {self.nome}! Você vai ter de ganhar mais dinheiro para comprar este item!")

    def use(self):
        item = ""
        while item not in [i for i in self.inventario]:
            print("\nEscolha apenas uma das opções da lista, por favor")
            item = input(f"Que item do teu inventário queres usar? Possibilidades: {set([f'{i} ({self.inventario.count(i)})' for i in self.inventario])}")

        self.weaponry += items[item]["weaponry"]
        self.armory += items[item]["armory"]
        self.pontos_vida += items[item]["pontos de vida"]

        # o jogador apenas poderá ter no máximo 100 pontos de vida
        pontos_de_vida_potenciais = self.pontos_vida + items[item]["pontos de vida"]
        if self.pontos_vida == 100 and items[item]["pontos de vida"] > 0:
            print(f"Tem o máximo possível de pontos de vida. Não pode usar {item}")
        else:
            if pontos_de_vida_potenciais <= 100:
                self.pontos_vida += items[item]["pontos de vida"]
                print(f"{self.nome} usou {item} do seu inventário.")
                self.inventario.remove(item)
            else:
                self.pontos_vida = 100
                print(f"{self.nome} usou {item} do seu inventário")
                self.inventario.remove(item)

    def sell(self, item):
        if item in self.inventario:
            self.money += round(items[item]["preço"] * 0.81)
            self.weaponry -= items[item]["weaponry"]
            self.armory -= items[item]["armory"]
            self.pontos_vida -= items[item]["pontos de vida"]
            self.inventario.remove(item)
            print(f"O {self.nome} vendeu uma unidade de {item} por {round(items[item]['preço'] * 0.81)}")
        else:
            print(f"Seu malandro! {item} não existe no seu inventário! Não pode vender este item!")

    def acontecer_evento(self, evento):
        print(evento["texto"])
        if evento["tipo"] == "money_event":
            self.money += evento["valor"]
        elif evento["tipo"] == "vida_event":
            self.pontos_vida += evento["valor"]
        elif evento["tipo"] == "wisdom_event":
            self.wisdom += evento["valor"]
        elif evento["tipo"] == "casa_jogo_event":
            self.casa_jogo += evento["valor"]
        elif evento["tipo"] == "mana_event":
            self.pontos_mana += evento["valor"]
        elif evento["tipo"] == "extra_life_event":
            self.pontos_vida *= 1 + evento["valor"]

    def lancar_dado(self):
        comprar = ""
        while comprar not in ["Sim", "Não"]:
            comprar = input(f"Queres comprar algum item na loja? Possibilidades: Sim/ Não")

            if comprar == "Sim":
                self.buy()

            elif comprar == "Não":
                break

        if len(self.inventario) == 0:
            pass
        else:
            usar = ""
            while usar not in ["Sim", "Não"]:
                usar = input(f"Queres usar algum item do teu inventário? Possibilidades: Sim/ Não")

                if usar == "Sim":
                    self.use()

                elif usar == "Não":
                    break

        dado_val = random.choice(range(1, 7))
        self.casa_jogo += dado_val
        print(f"Saiu o número {dado_val}")

        for i in eventos:
            if self.casa_jogo == eventos[i]["casa"]:
                self.acontecer_evento(eventos[i])
                break

        for i in range(len(jogadores)):
            prog = eval(f'player{i + 1}')

            if self == prog or prog.pontos_vida <= 0:
                continue
            elif self.casa_jogo == prog.casa_jogo:
                self.battle(prog)
                break

class Monster:
    def __init__(self):
        pass

    pontos_speed = 0
    pontos_mana = 0
    pontos_atk = 0
    pontos_def = 0
    wisdom = 0
    weaponry = 0
    armory = 0


# SubClasses!
class Druid(Player):
    def __init__(self, nome):
        super().__init__()
        self.nome = nome

    pontos_mana = 25
    pontos_atk = 20
    pontos_def = 15
    pontos_speed = 3


class Archer(Player):
    def __init__(self, nome):
        super().__init__()
        self.nome = nome

    pontos_mana = 20
    pontos_atk = 25
    pontos_def = 18
    pontos_speed = 3


class Beggar(Player):
    def __init__(self, nome):
        super().__init__()
        self.nome = nome

    pontos_mana = 15
    pontos_atk = 30
    pontos_def = 13
    pontos_speed = 4


class King(Player):
    def __init__(self, nome):
        super().__init__()
        self.nome = nome

    pontos_mana = 25
    pontos_atk = 25
    pontos_def = 15
    pontos_speed = 3


class Healer(Player):
    def __init__(self, nome):
        super().__init__()
        self.nome = nome

    pontos_mana = 30
    pontos_atk = 11
    pontos_def = 10
    pontos_speed = 4


class Slime(Monster):
    def __init__(self, nome):
        self.nome = nome

    pontos_vida = 20
    pontos_mana = 25
    pontos_atk = 17
    pontos_def = 10
    pontos_speed = 3


def criar_jogadores():
    global jogadores

    jogadores = {}
    # rotina para saber quantos jogadores jogam
    while True:
        try:
            numero_de_jogadores = int(input("Quantos jogadores vão a jogo? Indique um número.\n"))
            break
        except:
            print("insira um número, por favor")

    # rotina para saber o nome dos jogadores
    for jogador in range(numero_de_jogadores):
        player = input(f"Qual o nome do jogador {jogador + 1} \n")
        jogadores[f"Player {jogador + 1}"] = [player]

    # rotina para saber a classe dos jogadores
    for i in jogadores:
        classe = ""
        while classe not in [i.__name__ for i in Player.__subclasses__()]:
            print("\nEscolha apenas uma das opções da lista, por favor")
            classe = input(f"{jogadores[i][0]}, que tipo de jogador queres ser? Possibilidades: {sorted([i.__name__ for i in Player.__subclasses__()])}")
            if classe in [i.__name__ for i in Player.__subclasses__()]:
                jogadores[i].append(classe)

    # loop para gerar players, com classes, a partir do dicionário jogadores
    for i in range(len(jogadores)):
        prog = f"player{i + 1}=eval(jogadores[f'Player {i + 1}'][1])(jogadores['Player {i + 1}'][0])"
        exec(prog, globals())


def ranking():
    players = []
    for i in range(len(jogadores)):
        prog = eval(f'player{i + 1}')
        players.append(prog)

    print("Ranking Pontos de Vida:")
    jogadores_ordenados = sorted(players, key=lambda x: x.pontos_vida, reverse=True)
    for i in jogadores_ordenados:
        print(f'{i.nome}: {i.pontos_vida} pontos de vida')
    print()

    print("Ranking Dinheiro:")
    jogadores_ordenados = sorted(players, key=lambda x: x.money, reverse=True)
    for i in jogadores_ordenados:
        print(f'{i.nome}: {i.money} coins')
    print()

    print("Ranking Pontos de Sabedoria:")
    jogadores_ordenados = sorted(players, key=lambda x: x.wisdom, reverse=True)
    for i in jogadores_ordenados:
        print(f'{i.nome}: {i.wisdom} pontos de sabedoria')
    print()

    print("Posição no Jogo:")
    jogadores_ordenados = sorted(players, key=lambda x: x.casa_jogo, reverse=True)
    for i in jogadores_ordenados:
        print(f'{i.nome}: Está na casa de jogo {i.casa_jogo}')
    print()


# Turno de jogo
def inicio():
    criar_jogadores()
    bandeira = True
    while bandeira:
        for i in range(len(jogadores)):
            if bandeira:
                prog = eval(f'player{i + 1}')
                if prog.casa_jogo < 50:
                    if prog.pontos_vida > 0:
                        print(f"\nJogador em jogo: {prog.nome}")
                        prog.lancar_dado()
                    else:
                        print(f"{prog.nome} não joga. Está morto na casa {prog.casa_jogo}")
                        continue
                else:
                    print("\nFinal do jogo!\n")
                    ranking()
                    bandeira = False
        ranking()


items={
    "Sword":{
        "preço":30,
        "weaponry": 5,
        "armory":0,
        "pontos de vida": 0
    },
    
    "Shield":{
        "preço":25,
        "weaponry": 0,
        "armory":5,
        "pontos de vida": 0
    },
    
    "Live Potion":{
        "preço":15,
        "weaponry": 0,
        "armory":0,
        "pontos de vida": 35
    },
    
    "Banana":{
        "preço":5,
        "weaponry": 0,
        "armory":0,
        "pontos de vida": 10
    },
    
    "Thor Hammer":{
        "preço":50,
        "weaponry": 15,
        "armory":0,
        "pontos de vida": 0
    },
    
    "Armor":{
        "preço":35,
        "weaponry": 0,
        "armory":15,
        "pontos de vida": 0
    },
    
    "Rivers of Blood":{
        "preço":100,
        "weaponry": 40,
        "armory":10,
        "pontos de vida": 0
    },
    
    "Broken Blade of the Ruined King":{
        "preço":120,
        "weaponry": 35,
        "armory":0,
        "pontos de vida": 10
    },
}
casas_eventos = range(1, 51)

eventos={}

casas_eventos= range(1,51)

eventos={
    "Furacão":{
        "texto":"Foi apanhado por um furacão. Perde 10 pontos de vida",
        "tipo": "vida_event",
        "valor":-10,
        "casa": random.choice([i for i in casas_eventos if i not in [eventos[i]["casa"] for i in eventos]])
    },
    
    "Pote d'oiro":{
        "texto":"Encontrou um pote d'oiro. Ganha 15 coins",
        "tipo": "money_event",
        "valor":15,
        "casa": random.choice([i for i in casas_eventos if i not in [eventos[i]["casa"] for i in eventos]])
    },
    
    "Livro de Feitiços":{
        "texto":"Encontrou um livro de feitiços que lhe ensina um conjunto de coisas boas. Ganha 3 de wisdom",
        "tipo": "wisdom_event",
        "valor":3,
        "casa": random.choice([i for i in casas_eventos if i not in [eventos[i]["casa"] for i in eventos]])
    },
    
    "Javali":{
        "texto":"É surpreendido por um javali e tem que fugir e esconder-se. Recua 4 casas de jogo",
        "tipo": "casa_jogo_event",
        "valor":-4,
        "casa": random.choice([i for i in casas_eventos if i not in [eventos[i]["casa"] for i in eventos]])
    },
    
    "Carruagem":{
        "texto":"Oferecem-te boleia numa carruagem. Segue até ao próximo apeadeiro. Avança 3 casas de jogo",
        "tipo": "casa_jogo_event",
        "valor":+3,
        "casa": random.choice([i for i in casas_eventos if i not in [eventos[i]["casa"] for i in eventos]])
    },
    
    "Veado":{
        "texto":"Conseguiu caçar um veado. Ganha 20 pontos de vida",
        "tipo": "vida_event",
        "valor":+20,
        "casa": random.choice([i for i in casas_eventos if i not in [eventos[i]["casa"] for i in eventos]])
    },
    
    "Sponge Bob":{
        "texto":"Encontra o Bob Esponja das Calças Quadradas que lhe vende uma pedra, enganando-o. Perde 15 coins",
        "tipo": "money_event",
        "valor":-15,
        "casa": random.choice([i for i in casas_eventos if i not in [eventos[i]["casa"] for i in eventos]])
    },
    
    "Maldição":{
        "texto":f"O jogador à sua direita lança uma evocação maligna contra si. Perde 2 pontos de Wisdom",
        "tipo": "wisdom_event",
        "valor":-2,
        "casa": random.choice([i for i in casas_eventos if i not in [eventos[i]["casa"] for i in eventos]])
    },
    
    "Cobra venenosa":{
        "texto":"Uma cobra surpreende-o e morde-o. Perde 15 pontos de vida",
        "tipo": "vida_event",
        "valor":-15,
        "casa": random.choice([i for i in casas_eventos if i not in [eventos[i]["casa"] for i in eventos]])
    },
    
    "Cogumelo Venenoso":{
        "tipo": "vida_event",
        "texto":"Apanha um cogumelo e come-o. É um cogumelo venenoso! Perde 10 pontos de vida",
        "valor":-10,
        "casa": random.choice([i for i in casas_eventos if i not in [eventos[i]["casa"] for i in eventos]])
    },
    
    "Ruínas do Templo Sagrado":{
        "tipo": "mana_event",
        "texto":"No seu percurso, encontra as ruínas de um templo sagrado. Ganha 2 pontos adicionais de mana.",
        "valor":2,
        "casa": random.choice([i for i in casas_eventos if i not in [eventos[i]["casa"] for i in eventos]])
    },
    
    "Feiticeira":{
        "tipo": "extra_life_event",
        "texto":"Encontras uma boa feiticeira que te dá um conjunto de plantas medicinais que te fortalecem. Ganhas 20% dos teus pontos de vida",
        "valor":0.20,
        "casa": random.choice([i for i in casas_eventos if i not in [eventos[i]["casa"] for i in eventos]])
    },
    
}

inicio()
