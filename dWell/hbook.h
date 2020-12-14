#ifndef HBOOK_H
#define HBOOK_H

#include "book.h"
#include "habitant.h"

class hbook : public book
{
public:
    hbook();
    /**
     * @brief Оператор [].
     * @param idx Индекс читаемого элемента.
     * @return Константная ссылка на заметку.
     */
    const habitant &operator[](SizeType idx) const;

private:
    /// Внутренний контейнер для хранения проживающих.
    QVector<habitant> mHabitants;
};

#endif // HBOOK_H
