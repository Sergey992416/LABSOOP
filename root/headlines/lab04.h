#pragma once
#include <stdio.h>
namespace lab04 {
	void runDemo();
    class DATE {
    public:
        DATE(unsigned int day, unsigned int mon, unsigned int year);

        virtual ~DATE();

        virtual void Print(char smb) const;

        virtual DATE Sub(const DATE& what) const;

        void PrintSub(const DATE& other, char smb) const;

        // Добавляем геттеры для доступа к защищённым данным
        unsigned int GetDay() const { return day; }
        unsigned int GetMonth() const { return mon; }
        unsigned int GetYear() const { return year; }

    protected:
        unsigned int day, mon, year;
    };

    class ExtendedDATE : public DATE {
    public:
        ExtendedDATE(unsigned int day, unsigned int mon, unsigned int year,
            unsigned int hours, unsigned int minutes);

        ~ExtendedDATE();

        void Print(char smb) const override;

        DATE Sub(const DATE& what) const override;

    private:
        unsigned int hours, minutes;
    };
}
