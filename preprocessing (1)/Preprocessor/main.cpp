#include <QDebug>
#include <QCoreApplication>
#include "preprocessor.h"

void test_preprocessor() {
    Preprocessor prep;

    qDebug() << "Test 1";
    std::vector<Token> tokens1 = {
        {TokenType::HASH, "#"},
        {TokenType::IDENTIFIER, "define"},
        {TokenType::IDENTIFIER, "MAX"},
        {TokenType::NUMBER, "100"},
        {TokenType::NEWLINE, "\n"},
        {TokenType::IDENTIFIER, "MAX"},
        {TokenType::END_OF_FILE, ""}
    };

    auto result1 = prep.process(tokens1);
    qDebug() << "Input tokens:" << tokens1.size();
    qDebug() << "Output tokens:" << result1.size();

    for (const auto& tok : result1) {
        qDebug() << "Token:" << QString::fromStdString(tok.value)
        << "Type:" << static_cast<int>(tok.type);
    }
    qDebug() << "\n"; //first test passed

    qDebug() << "Test 2";
    std::vector<Token> tokens = {
        {TokenType::HASH, "#"},
        {TokenType::IDENTIFIER, "ifndef"},
        {TokenType::IDENTIFIER, "DEBUG"},
        {TokenType::NEWLINE, "\n"},
        {TokenType::IDENTIFIER, "include_this"},
        {TokenType::NEWLINE, "\n"},
        {TokenType::HASH, "#"},
        {TokenType::IDENTIFIER, "endif"},
        {TokenType::NEWLINE, "\n"},
        {TokenType::END_OF_FILE, ""}
    };

    auto result = prep.process(tokens);

    qDebug() << "Input tokens:" << tokens.size();
    qDebug() << "Output tokens:" << result.size();
}

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    //test_preprocessor();

    return 0;
}
