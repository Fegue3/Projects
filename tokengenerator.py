#Password generator
import random 
import string


def Token_generator(length):
    characters = string.ascii_letters + string.digits + string.punctuation
    token = ''.join(random.choice(characters) for _ in range (length))
    return token

token_length = 32

generated_token = Token_generator(token_length)

print(f"Token gerado: {generated_token}")

    