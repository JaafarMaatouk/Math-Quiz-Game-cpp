# Math Quiz Game (C++)

An interactive console-based Math Quiz Game built in C++. The application tests the user's arithmetic skills by generating random math questions based on user-defined preferences.

## 🎮 Features
- Customizable Gameplay: Players can choose the number of questions, difficulty level (Easy, Medium, Hard, Mix), and operation type (Addition, Subtraction, Multiplication, Division, Mix).
- Random Question Generation: Creates unique math problems every time you play.
- Instant Feedback: 
  - Correct answers turn the console screen Green.
  - Wrong answers turn the screen Red and play a sound alert, while showing the correct answer.
- Detailed Final Report: Displays the total number of questions, difficulty level, operation type, number of correct/wrong answers, and whether the player Passed or Failed.
- Replayability: Allows the user to play multiple rounds without restarting the program.

## 🛠️ Technical Details
- Uses structs to manage Question and Quiz data.
- Implements enums for clean and readable difficulty levels and operation types.
- Utilizes rand() and srand() for dynamic question generation.
- Uses system("color") to change the console text and background colors for immediate visual feedback.

## 🚀 How to Run
1. Clone this repository or download it as a ZIP file.
2. Open the .sln file in Visual Studio.
3. Press F5 or Ctrl + F5 to build and run the game.
4. Follow the on-screen instructions to start your math quiz!

## 📄 License
This project is open-source and available under the MIT License.
