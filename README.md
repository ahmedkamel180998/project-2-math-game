# Math Game [Procedural Programming]
A simple math quiz game console application in C++ that challenges users with various math questions. Players can choose the difficulty level, type of operations, and number of questions. After completing the quiz, they can see their results and decide whether to play again.

## Table of Contents
- [Live Demo](#Live-Demo)
- [Features](#features)
- [How It Works](#how-it-works)
- [Game Flow](#game-flow)

## Live Demo
https://github.com/user-attachments/assets/a81b08dd-3952-445e-8cab-016e57f9216a

## Features
- Supports multiple question levels: Easy, Medium, Hard, and Mixed.
- Offers various mathematical operations: Addition, Subtraction, Multiplication, Division, and Mixed Operations.
- Generates random math questions based on the selected difficulty and operation.
- Provides feedback on each answer (Right or Wrong).
- Tracks and displays final results after the quiz is completed.
- Simple user interface with color-based feedback for right/wrong answers.
- Option to replay the game after completing the quiz.

## How It Works
1. The user selects the number of questions they wish to answer.
2. The user chooses a global difficulty level and a type of math operation.
3. Based on the global settings, the game generates random questions, displays them, and prompts the user for answers.
4. After each question, the user receives instant feedback (right or wrong) with colored screen updates.
5. The final results are shown, including the number of right and wrong answers, question level, and operation type.
6. The user has the option to play again.

## Game Flow
1. **Start**: 
   - The game starts by asking how many questions the player wants to answer.
   - The player selects a global difficulty level and math operation type.
   
2. **Question Generation**: 
   - The game generates questions based on the player's chosen difficulty and operation type.
   - Each question is shown on the screen with a simple arithmetic expression (e.g., 5 + 3).
   
3. **User Interaction**: 
   - The player inputs their answer for each question.
   - After submitting an answer, the game checks if it's correct and provides feedback (green screen for correct, red for incorrect).
   
4. **Final Results**: 
   - After answering all questions, the game summarizes the player's performance.
   - If the player has more right answers than wrong ones, they pass; otherwise, they fail.
   
5. **Replay**: 
   - The player can choose to replay the game or exit.
