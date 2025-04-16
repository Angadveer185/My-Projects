import speech_recognition as sr
import pyttsx3
import pywhatkit
import wikipedia
import datetime
import random

# Initialize text-to-speech engine
engine = pyttsx3.init()

# Define a function to speak a given text
def speak(text):
    engine.say(text)
    engine.runAndWait()

# Define a function to recognize speech using Google's speech recognition API
def recognize_speech():
    recognizer = sr.Recognizer()
    with sr.Microphone() as source:
        audio = recognizer.listen(source)
        try:
            text = recognizer.recognize_google(audio)
            print("You said:", text)
            return text
        except:
            return ""

# Define a function to play a song on YouTube
def play_song_on_youtube(song_name):
    pywhatkit.playonyt(song_name)

# Define a function to get the current time
def get_time():
    now = datetime.datetime.now()
    current_time = now.strftime("%H:%M")
    speak("The current time is " + current_time)

# Define a function to search Wikipedia for a given topic
def search_wikipedia(topic):
    results = wikipedia.summary(topic, sentences=2)
    speak(results)

# Define a function to tell a joke
def tell_joke():
    jokes = [
        "Why did the tomato turn red? Because it saw the salad dressing!",
        "Why don't scientists trust atoms? Because they make up everything.",
        "Why was the math book sad? Because it had too many problems.",
    ]
    joke = random.choice(jokes)
    speak(joke)

# Main loop
while True:
    # Listen for a command
    speak("How can I help you?")
    command = recognize_speech()

    # Execute the command
    if "play" in command:
        song_name = command.replace("play", "").strip()
        speak("Playing " + song_name + " on YouTube.")
        play_song_on_youtube(song_name)
    elif "time" in command:
        get_time()
    elif "search" in command:
        topic = command.replace("search", "").strip()
        speak("Searching Wikipedia for " + topic)
        search_wikipedia(topic)
    elif "joke" in command:
        tell_joke()
    elif "exit" in command:
        speak("Goodbye!")
        break
