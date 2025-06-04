import random
import requests

def choose_word():
    try:
        response = requests.get("https://random-word-api.herokuapp.com/word?number=1")
        if response.status_code == 200:
            return response.json()[0]
    except Exception as e:
        print("Error fetching word, using default list.")
    words = ['python', 'hangman', 'developer', 'challenge', 'programming']
    return random.choice(words)

def display(word, guessed_letters):
    return ' '.join(letter if letter in guessed_letters else '_' for letter in word)

def hangman():
    word = choose_word()
    guessed_letters = set()
    attempts = 6

    print("Welcome to Hangman!")

    while attempts > 0:
        print("\n" + display(word, guessed_letters))
        print(f"You have already used the letters {guessed_letters}")
        guess = input("Guess a letter: ").lower()

        if guess in guessed_letters:
            print("You already guessed that letter!")
            continue

        guessed_letters.add(guess)

        if guess not in word:
            attempts -= 1
            print(f"Incorrect! You have {attempts} attempts left.")

        if display(word, guessed_letters) == word:
            print(f"Congratulations! You guessed the word: {word}")
            return

        if guess in word:
            print(f"Correct! The letter {guess} is in the word. You still have {attempts} attempts left.")

    print(f"Game over! The word was: {word}")

if __name__ == "__main__":
    hangman()
