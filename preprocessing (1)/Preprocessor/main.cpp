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
    qDebug() << "\n";
}

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    test_preprocessor();

    return 0;
}
