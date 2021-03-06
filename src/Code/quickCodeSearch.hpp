#pragma once

#include <QObject>
#include <QTextCursor>

#include "quickQmlRegister.hpp"

namespace quick {

    namespace Code {

        class Search : public QObject {
            Q_OBJECT
            Q_PROPERTY(QString findString READ getFindString WRITE setFindString NOTIFY findStringChanged);
            Q_PROPERTY(QString replaceString READ getReplaceString WRITE setReplaceString NOTIFY replaceStringChanged);
            Q_PROPERTY(QString regexError READ getRegexError NOTIFY regexErrorChanged);
            Q_PROPERTY(int currentMatch READ getCurrentMatch NOTIFY currentMatchChanged);
            Q_PROPERTY(int matchCount READ getMatchCount NOTIFY matchCountChanged);
            Q_PROPERTY(bool caseSensitive READ getCaseSensitive WRITE setCaseSensitive NOTIFY caseSensitiveChanged);
            Q_PROPERTY(bool useRegex READ getUseRegex WRITE setUseRegex NOTIFY useRegexChanged);
            Q_PROPERTY(bool regexValid READ getRegexValid NOTIFY regexValidChanged);
        private:
            QList<QTextCursor> m_matches;
            QString m_findString;
            QString m_replaceString;
            QString m_regexError;
            bool m_regexValid = true;
            bool m_caseSensitive = false;
            bool m_useRegex = false;
            bool m_valid = false;
            int m_currentMatch = -1;
        private:
            static Qml::Register::Type<Search> Register;
        public:
            Search() = default;
            auto processSearch() -> void;
            auto setCaseSensitive(bool) -> void;
            auto getCaseSensitive() -> bool;
            auto setUseRegex(bool) -> void;
            auto getUseRegex() -> bool;
            auto checkRegex() -> void;
            auto setRegexValid(bool) -> void;
            auto getRegexValid() -> bool;
            auto setRegexError(const QString&) -> void;
            auto getRegexError() -> QString;
            auto setFindString(const QString&) -> void;
            auto getFindString() -> QString;
            auto setReplaceString(const QString&) -> void;
            auto getReplaceString() -> QString;
            auto setCurrentMatch(int) -> void;
            auto getCurrentMatch() -> int;
            auto getMatchCount() -> int;
            auto invalidate() -> void;
        public slots:
            void findNext();
            void findPrevious();
            void replaceNext();
            void replaceAll();
        signals:
            void show();
            void hide();
            void useRegexChanged();
            void regexErrorChanged();
            void regexValidChanged();
            void findStringChanged();
            void currentMatchChanged();
            void caseSensitiveChanged();
            void replaceStringChanged();
            void matchCountChanged();
        };
    }
}
