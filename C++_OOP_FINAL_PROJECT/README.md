
# Final C++ Project Submission

## ✅ Assigned Project Title:  
**Restaurant Menu & Orders System**

---

## 🧠 Assigned Task Description

Build a C++ restaurant ordering system using:

- A `struct MenuItem` with a static array of 20 items.
- An **abstract base class `OrderBase`** with a pure virtual `float totalCost()` method.
- Two **derived classes**:
  - `DineInOrder` with `float* serviceCharge`
  - `TakeOutOrder` with `float* packagingFee`
- Each order holds a `MenuItem** selectedItems` array dynamically allocated.
- Use **pointer arithmetic** to compute totals.
- Use `OrderBase*` objects in a `OrderBase** orders` array.
- Add and remove orders using dynamic resizing.

---

## 💪 How the Task Was Completed

1. **Struct Implementation**
   - Defined `struct MenuItem { char name[30]; float price; };`
   - Populated `MenuItem menu[20]` statically with 10 sample food items.

2. **OOP Design**
   - Created abstract class `OrderBase` with:
     - A dynamic array of `MenuItem*` (via `MenuItem** selectedItems`)
     - A pure virtual function `float totalCost()` for polymorphism.
   - Derived two classes:
     - `DineInOrder` that adds a `float* serviceCharge`
     - `TakeOutOrder` that adds a `float* packagingFee`
   - Both override `totalCost()` to return item total + respective fee.

3. **Pointer Use**
   - Orders store items dynamically using `MenuItem**`.
   - Prices are calculated using pointer dereferencing and pointer arithmetic.
   - `OrderBase*` pointers stored in a `OrderBase** orders` array for polymorphic behavior.

4. **Dynamic Memory**
   - Arrays are resized manually using `new` and `delete` when adding/removing orders.

5. **User Interface**
   - Simple text-based menu in `main()`:
     - Show menu
     - Add dine-in or take-out order
     - View all orders
     - Remove order
     - Exit

6. **Code Annotation**
   - Every line in `main.cpp` is commented to explain its function.

---

## 💬 Code Annotation Summary

- ✅ Struct for static menu
- ✅ Inheritance and polymorphism
- ✅ Pointers to pointers (2D logic)
- ✅ Manual memory management
- ✅ Full inline code comments in `main.cpp`

> See `main.cpp` for full code and annotations.

---

## 📄 Screenshots of Resulting Outputs

> Place screenshots in the `screenshots/` folder and update paths if needed.

### 1️⃣ Main Menu
![Main Menu](screenshots/main_menu.png)

### 2️⃣ Adding Dine-In Order
![Dine-In Order](screenshots/dine_in.png)

### 3️⃣ Adding Take-Out Order
![Take-Out Order](screenshots/take_out.png)

### 4️⃣ Viewing Orders
![View Orders](screenshots/view_orders.png)

### 5️⃣ Removing an Order
![Remove Order](screenshots/remove_order.png)

---

## ⚙️ How to Compile & Run

```bash
g++ main.cpp -o restaurant
./restaurant
```

> Make sure you're using a C++11+ compiler. Works on Linux, Windows (MinGW), and macOS.

---

## 📃 Student Info

**👤 Name:** _Your Full Name_  
**🎓 Course:** C++ Programming / Final Project  
**📆 Date:** _Submission Date Here_  
**🧠 Topic:** Pointers, Inheritance, Dynamic Arrays, Polymorphism
