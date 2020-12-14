#ifndef BOOK_H
#define BOOK_H

#include <QAbstractTableModel>
#include <QDataStream>
#include <QVector>

#include "bookentry.h"

class book : public QAbstractTableModel
{
    Q_OBJECT
public:
    /**
     * @brief Тип индексов и размера контейнера.
     *
     * Используется int, так как это тип индексов строк в QAbstractTableModel.
     * В то же время, в стандартных контейнерах C++ (std::vector и др.) для этого
     * применяются беззнаковые типы.
     */
    using SizeType = int;

    /// Конструктор по умолчанию.
    //book();
    /**
     * @brief Оператор [].
     * @param idx Индекс читаемого элемента.
     * @return Константная ссылка на заметку.
     */
    virtual const bookentry &operator[](SizeType idx) const;
    /// Определяет размер коллекции (количество заметок).
    virtual SizeType size() const;

    /**
     * @name Реализация интерфейса модели.
     *
     * Ниже идут методы, являющиеся определениями методов интерфейса
     * модели. Подробное описание их предназначения и требований к ним можно
     * найти в документации классов Qt QAbstractTableModel, QAbstractItemModel.
     * @{
     */
    /**
     * @brief Определяет количество строк в модели (заметок).
     * @param parent Ссылка на индекс родительского объекта.
     * @note Q_DECL_OVERRIDE — это макроконстанта (\#define), которая заменяется
     * спецификатором @c override, если компилятор его поддерживает. Этот спецификатор
     * означает, что данный метод является переопределением соответствующего
     * метода базового класса.
     */
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    /**
     * @brief Определяет количество столбцов в модели.
     * @param parent Ссылка на индекс родительского объекта.
     */
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    /**
     * @brief Возвращает данные указанной роли для указанного элемента модели.
     * @param index Индекс элемента модели.
     * @param role Роль, для которой надо вернуть данные.
     */
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    /**
     * @brief Возвращает данные указанной роли для указанного заголовка модели.
     * @param section Раздел заголовка (номер строки для вертикального заголовка
     * или номер столбца для горизонтального).
     * @param orientation Ориентация заголовка (вертикальный — заголовок строк,
     * горизонтальный — заголовок столбцов).
     * @param role Роль, для которой надо вернуть данные.
     */
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    /// @}
    // Конец реализации интерфейса модели
};

#endif // BOOK_H
