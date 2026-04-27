# Задачи

## 1. Computer
Реализирайте клас **Computer Peripheral**:
 - `model` - модел
 - `price` - цена
 - `manufacturer` - производител

Има getter-и и setter за price.

Реализирайте класове за различни видове периферни устройства:
 - **Mouse**:
    - `connectivity` - Тип свързаност (с кабел, без кабел)
 - **Keyboard**
    - `color` - цвят
    - `language` - език вурху копчетата [EN, BG, ES, FR, DE] *(може да имаме комбинация от до два езика)*
 - **Monitor**
    - `refresh rate` - херци
    - `size` - размер на екарана
 - **Headphones**
    - `connectivity` - Тип свързаност (с кабел, без кабел)
    - `microphone` - дали имат микрофон или не

---

## 2. School
Реализирайте клас **Person**:
 - `name` - име
 - `age` - години

Реализирайте класовете:
 - **Principal**
    - `room`
 - **Teacher**
    - `subjects` - колекция от предмети, които води
 - **Student**
    - `grades` - двойки от предмет и оценка по него

---

## 3. Shape
Реализирайте клас **Shape**:
 - `color` - цвят

Функционалност:
 - `getColor()` - принтира цвета

Реализирайте класове:
 - **Rectangle**
    - `width`
    - `length`
    - `getArea()`
 - **Triangle**
    - `a`
    - `b`
    - `c`
    - `getArea()`
 - **Circle**
    - `radius`
    - `getArea()`
 - **Square** - *помислете какво да наследи*
    - `side`
    - `getArea()`