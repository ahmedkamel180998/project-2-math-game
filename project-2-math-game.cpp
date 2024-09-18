#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

enum enQuestionsLevel { easy = 1, medium = 2, hard = 3, mixedQ = 4 };

enum enOperationType { addition = 1, subtraction = 2, multiplication = 3, division = 4, mix = 5 };

enum enAnswerType { rightAnswer = 1, wrongAnswer = 2 };

enum enFinalResult { pass = 1, fail = 2 };


struct stQuestionInfo {
	short questionNumber = 0;
	enQuestionsLevel localQuestionsLevel = enQuestionsLevel::easy;
	enQuestionsLevel globalQuestionsLevel = enQuestionsLevel::easy;
	short firstInteger = 0;
	short secondInteger = 0;
	enOperationType localOperationType = enOperationType::addition;
	enOperationType globalOperationType = enOperationType::addition;
	char operationSign = '+';
	short userAnswer = 0;
	short rightAnswer = 0;
	enAnswerType answerType = enAnswerType::rightAnswer;
};

struct stMathGameResults {
	short questionsNumbers = 0;
	enQuestionsLevel questionLevel = enQuestionsLevel::easy;
	string questionsLevelName;
	enOperationType operationType = enOperationType::addition;
	string operationTypeName;
	short rightAnswersNumber = 0;
	short wrongAnswersNumber = 0;
};

short readNumber(string message) {
	short number;
	cout << message << endl;
	cin >> number;
	return number;
}

short readPositiveNumber(string message) {
	short positiveNumber;

	do
	{
		cout << message << endl;
		cin >> positiveNumber;
	} while (positiveNumber <= -1);
	return positiveNumber;
}

short readNumberInRange(string message, short from, short to) {
	short numberInRange;

	do
	{
		cout << message << endl;
		cin >> numberInRange;
	} while (numberInRange < from || numberInRange > to);

	return numberInRange;
}

short getRandomNumber(short lowerBound, short upperBound) {
	short randomNumber = (rand() % (upperBound - lowerBound) + 1 + lowerBound);
	return randomNumber;
}

short howManyQuestions() {
	return readPositiveNumber("How Many Questions Do You Want To Answer ?");
}

// Screen Formatting Functions

string tabs(short howManyTabs) {
	string tabs = "";

	for (short i = 0; i < howManyTabs; i++)
	{
		tabs = tabs + "\t";
	}
	return tabs;
}

string newLines(short howManyTabs) {
	string newLines = "";

	for (short i = 0; i < howManyTabs; i++)
	{
		newLines = newLines + "\n";
	}
	return newLines;
}

void showFinalResultIsPassOrFailScreen(enFinalResult finalResults) {
	switch (finalResults)
	{
	case enFinalResult::pass:
		cout << tabs(4) << "--------------------------------------------------------" << newLines(2);
		cout << tabs(4) << "----------------- Final Result Is Pass -----------------" << newLines(2);
		cout << tabs(4) << "--------------------------------------------------------" << newLines(2);
		break;
	case enFinalResult::fail:
		cout << tabs(4) << "--------------------------------------------------------" << newLines(2);
		cout << tabs(4) << "----------------- Final Result Is Fail -----------------" << newLines(2);
		cout << tabs(4) << "--------------------------------------------------------" << newLines(2);
		break;
	}
}

void setAnswerScreenColor(enAnswerType answerType) {
	switch (answerType)
	{
	case enAnswerType::rightAnswer:
		system("color 2F");
		break;
	case enAnswerType::wrongAnswer:
		system("color 4F");
		cout << "\a";
		break;
	}
}

void setFinalResultScreenColor(enFinalResult finalResult) {
	switch (finalResult)
	{
	case enFinalResult::pass:
		system("color 2F");
		break;
	case enFinalResult::fail:
		system("color 4F");
		cout << "\a";
		break;
	}
}

void resetScreen() {
	system("cls");
	system("color 0F");
}

// end Screen Formatting Functions

enQuestionsLevel readGlobalQuestionsLevel() {
	return (enQuestionsLevel)readNumberInRange("Enter Questions Level: [1] Easy, [2] Medium, [3] Hard, [4] Mix", 1, 4);
}

enQuestionsLevel getLocalQuestionLevel(enQuestionsLevel globalQuestionLevel) {
	if (globalQuestionLevel == 4)
		return (enQuestionsLevel)getRandomNumber(1, 3);
	else
		return globalQuestionLevel;
}

string questionsLevelName(enQuestionsLevel questionsLevel) {
	string questionsLevelName[4] = { "Easy", "Medium", "Hard", "Mixed Questions" };
	return questionsLevelName[questionsLevel - 1];
}

enOperationType readGlobalOperationType() {
	return (enOperationType)readNumberInRange("Enter Operation Type: [1] Addition, [2] Subtraction, [3] Multiplication, [4] Division, [5] Mix", 1, 5);
}

enOperationType getLocalOperationType(enOperationType globalOpeartionType) {
	if (globalOpeartionType == 5)
		return (enOperationType)getRandomNumber(1, 4);
	else
		return globalOpeartionType;
}

string operationTypeName(enOperationType operationType) {
	string operationTypeName[5] = { "Addition", "Subtraction", "Multiplication", "Division", "Mixed Operations" };
	return operationTypeName[operationType - 1];
}

short getFirstInteger(enQuestionsLevel questionsLevel) {
	switch (questionsLevel)
	{
	case enQuestionsLevel::easy:
		return getRandomNumber(1, 9);
	case enQuestionsLevel::medium:
		return getRandomNumber(10, 49);
	case enQuestionsLevel::hard:
		return getRandomNumber(50, 99);
	}
}

short getSecondInteger(enQuestionsLevel questionsLevel) {
	switch (questionsLevel)
	{
	case enQuestionsLevel::easy:
		return getRandomNumber(1, 9);
	case enQuestionsLevel::medium:
		return getRandomNumber(10, 49);
	case enQuestionsLevel::hard:
		return getRandomNumber(50, 99);
	}
}

short readUserAnswer() {
	return readNumber("Your Answer ?");
}

char operationSign(enOperationType operationType) {
	char operationSign[4] = { '+', '-', '*', '/' };
	return operationSign[operationType - 1];
}

short doOperation(enOperationType operationType, short firstInteger, short secondInteger) {
	switch (operationType)
	{
	case enOperationType::addition:
		return firstInteger + secondInteger;
	case enOperationType::subtraction:
		return firstInteger - secondInteger;
	case enOperationType::multiplication:
		return firstInteger * secondInteger;
	case enOperationType::division:
		return firstInteger / secondInteger;
	}
}

enAnswerType checkAnswer(short userAnswer, short rightAnswer, short firstInteger, short secondInteger) {
	if (userAnswer == rightAnswer)
		return enAnswerType::rightAnswer;
	else
		return enAnswerType::wrongAnswer;
}

void showQuestionInfo(stQuestionInfo questionInfo) {
	cout << tabs(2) << questionInfo.firstInteger << endl;
	cout << tabs(3) << questionInfo.operationSign << endl;
	cout << tabs(2) << questionInfo.secondInteger << endl;
	cout << tabs(2) << "------------------------" << endl;
}

void showAnswer(stQuestionInfo questionInfo) {
	if (questionInfo.answerType == enAnswerType::rightAnswer)
	{
		cout << tabs(2) << "Right Answer!" << endl;
		setAnswerScreenColor(questionInfo.answerType);
	}
	else
	{
		cout << tabs(2) << "Wrong Answer!" << endl;
		cout << tabs(2) << "The Right Answer Is: " << questionInfo.rightAnswer << endl;
		setAnswerScreenColor(questionInfo.answerType);
	}
}

stMathGameResults fillGameResults(short questionsNumber, enQuestionsLevel questionLevel, enOperationType operationType, short rightAnswersNumber, short wrongAnswersNumber) {
	stMathGameResults mathGameResults;

	mathGameResults.questionsNumbers = questionsNumber;
	mathGameResults.questionLevel = questionLevel;
	mathGameResults.questionsLevelName = questionsLevelName(questionLevel);
	mathGameResults.operationType = operationType;
	mathGameResults.operationTypeName = operationTypeName(operationType);
	mathGameResults.rightAnswersNumber = rightAnswersNumber;
	mathGameResults.wrongAnswersNumber = wrongAnswersNumber;

	return mathGameResults;
}

stMathGameResults quiz(short howManyQuestions) {
	stQuestionInfo questionInfo;
	short rightAnswersNumber = 0, wrongAnswersNumber = 0;

	questionInfo.globalQuestionsLevel = readGlobalQuestionsLevel();
	questionInfo.globalOperationType = readGlobalOperationType();

	for (int i = 1; i <= howManyQuestions; i++)
	{
		cout << "Question [" << i << "/" << howManyQuestions << "]" << endl;
		questionInfo.questionNumber = i;
		questionInfo.localQuestionsLevel = getLocalQuestionLevel(questionInfo.globalQuestionsLevel);
		questionInfo.firstInteger = getFirstInteger(questionInfo.localQuestionsLevel);
		questionInfo.secondInteger = getSecondInteger(questionInfo.localQuestionsLevel);
		questionInfo.localOperationType = getLocalOperationType(questionInfo.globalOperationType);
		questionInfo.operationSign = operationSign(questionInfo.localOperationType);
		questionInfo.rightAnswer = doOperation(questionInfo.localOperationType, questionInfo.firstInteger, questionInfo.secondInteger);

		// show question Info
		showQuestionInfo(questionInfo);

		questionInfo.userAnswer = readUserAnswer();
		questionInfo.answerType = checkAnswer(questionInfo.userAnswer, questionInfo.rightAnswer, questionInfo.firstInteger, questionInfo.secondInteger);

		// counter
		if (questionInfo.answerType == enAnswerType::rightAnswer)
			rightAnswersNumber += 1;
		else
			wrongAnswersNumber += 1;

		// show answer info
		showAnswer(questionInfo);
	}

	// fill game results
	return fillGameResults(howManyQuestions, questionInfo.globalQuestionsLevel, questionInfo.globalOperationType, rightAnswersNumber, wrongAnswersNumber);
}

enFinalResult finalGameResults(stMathGameResults gameResults) {
	if (gameResults.rightAnswersNumber > gameResults.wrongAnswersNumber)
		return enFinalResult::pass;
	else
		return enFinalResult::fail;
}

void showFinalGameResults(stMathGameResults gameResults) {
	cout << tabs(4) << "--------------- [Math Game Results] --------------" << newLines(2);
	cout << tabs(4) << "Questions Number: " << gameResults.questionsNumbers << endl;
	cout << tabs(4) << "Questions Level: " << gameResults.questionsLevelName << endl;
	cout << tabs(4) << "Operation Type: " << gameResults.operationTypeName << endl;
	cout << tabs(4) << "Right Answers Number: " << gameResults.rightAnswersNumber << endl;
	cout << tabs(4) << "Wrong Answers Number: " << gameResults.wrongAnswersNumber << endl;
	cout << tabs(4) << "--------------------------------------------------" << newLines(2);

	setFinalResultScreenColor(finalGameResults(gameResults));
}

char playAgain() {
	char playAgain;
	do
	{
		cout << tabs(4) << "Do You Want To Play Again ? [Y/N]" << endl;
		cout << tabs(4);
		cin >> playAgain;
	} while (playAgain != 'Y' && playAgain != 'y' && playAgain != 'N' && playAgain != 'n');
	return playAgain;
}

void startMathGame() {
	stMathGameResults mathGameResults;

	char replay = 'y';

	do
	{
		resetScreen();
		mathGameResults = quiz(howManyQuestions());
		showFinalResultIsPassOrFailScreen(finalGameResults(mathGameResults));
		showFinalGameResults(mathGameResults);
		replay = playAgain();
	} while (replay == 'Y' || replay == 'y');
}

int main()
{
	srand((unsigned)time(NULL));
	startMathGame();
	return 0;
}