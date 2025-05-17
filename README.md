# 🍔✨ Puduk Eats
🛠️ A handmade terminal-based restaurant & order ecosystem built with pure C++ and file-based logic — no SQL, no GUI, just pointer magic.

---
## Made by [puduk](https://github.com/puduk)
---

A fully-functional fast food simulation system designed for terminal use only.  
Everything — from accounts to recipes, stock to promotions — is handled using `.txt` files and raw pointer-based dynamic memory.

💻 — built as a pointer challenge project, future versions will clean up and modularize the code.

---

## 🔥 Core Features

### 👥 Account System  
🧑‍🍳 Create & login as Customer or Restaurant Owner  
🔐 Password-protected access  
🧾 Forgot Password system for both user types  
📂 Each account has its own unique .txt file  
🚫 Duplicate checks prevent reused usernames and restaurant name

---

### 🍽️ Customer Panel  
🛒 Order food (reads recipe, updates stock dynamically)  
📜 View order history (auto-logged with timestamps)  
💳 Top-up account & save card data  
🏠 Change delivery address or phone number  
🧠 “Suggest Me a Meal” — fun mini test for recommendations  
🏷️ Apply promo code (only once per code)  
🛠️ Contact customer service (anonymous problem report)  
⭐ Rate the app on exit

---

### 🏢 Restaurant Panel  
➕ Add new product (name, price, calories, allergy, portion)  
❌ Delete product (removed from list)  
🔁 Update product portion or price  
📦 Check & update stock (auto-checked per recipe when ordered)  
🎁 Create and list promo codes  
🚦 Open or close restaurant status  
🗂️ All restaurant data saved in their own .txt files

---

## 📦 Recipe System  
📁 Each product has its own `.txt` recipe file  
➕ Dynamic array to hold ingredients — initial size: 5  
📏 Auto-resizes if more than 5 ingredients are needed  
🔄 Full pointer control (heap allocation & deletion)

---

## 💳 Top-Up & Card Storage  
💰 Balance updates shown live after orders and promotions  
💳 Saved cards stored securely in user files  
📎 Reusable during checkout without re-entering card data

---

## ⭐ App Rating System  
📝 Before quitting, both customers and restaurants are asked to rate  
📈 Scores stored and reviewed from `customer_rate.txt` and `restaurant_rate.txt`

---

## 📁 File-Based Storage  
✅ No SQL or external DBs  
📂 All data handled via structured `.txt` files  
🧼 Clear separators (like /-/) used for clean parsing  
🧠 Dynamically processed at runtime using file I/O

---

## 🧠 Code Structure & Practices  
🔗 All data is dynamically allocated on the heap using raw pointers  
🧃 Manual use of `new` and `delete` — no vectors, no arrays, no structs  
🛠️ Pure OOP with multiple `.cpp` and `.hpp` modules  
🧪 Manually tested — stable memory usage, no leaks  
📋 Modular menus with full logic flow control

---

## 🧠 Purpose  
This project was developed as a personal challenge to master pointer management, heap memory, and text-based data handling.  
The goal was to simulate a working app **without databases, structs, or helper libraries**.

---

## 🌱 Planned Upgrades (Summer or Fall 2025)

🖥️ GUI Version using Qt   
📐 Code cleanup and reduction of pointer overuse  
🔗 SQL-based backend version  
🌍 Multi-language support: 🇹🇷 Turkish, 🇷🇺 Russian, 🇵🇱 Polish  
🧩 Modular architecture and class separation  
📊 Analytics dashboard for restaurant owners

---

## 💻 Tech Stack

- 🚀 C++ (OOP, File I/O, Pointers)
- 📟 100% Terminal UI
- 🔁 No third-party libraries
- 🧠 Heap-only data storage
- 📁 Plaintext `.txt` database

---


## 💡 Notes

- ✅ Project contains **68 files** including `.cpp` & `.hpp`
- 🔁 Data fully preserved between sessions using file I/O
- ⏱️ Created from scratch in **~17 Hours** of focused coding


---

## 🧠 Advanced Concepts & Code Practices

- 🔗 All data is dynamically allocated on the **heap** using raw pointers  
- 🧠 Maximum usage of `new` / `delete` and deep manual memory management  
- 🚫 No use of helper tools like `struct`, `vector`, `array`, or `smart pointers`  
- 🧼 Code was repeatedly tested — **no discovered memory leaks**  
- 🛠 Designed with a deep focus on logic, control flow, and data isolation  
- 🧃 Pure, pointer-based simulation — zero shortcuts

---

## 🤖 AI Support (1%)


This project was 99% handwritten with manual logic and file design.  
Approximately 1% of assistance was provided by ChatGPT for **logic validation**, **debugging ideas**, and for generating **test questions and results** used in the *"Suggest Me a Meal"* feature.

> ❌ No AI-generated code was copied or directly implemented — all logic was self-written and fully understood.

---

## ⏱️ Timeline  
🧠 Development Time: ~3 Days  
💥 This project stands as one of the largest — 3,300+ lines in a single app

---

Crafted by a student with just 1 month of C++ experience in 3 days.
---

## 📸 Sample Terminal Flow

> Below is a real user experience from launching the app to placing an order, topping up balance, and managing stock.



## Opening Page
```
------------------------------------
1 :: for user sign in.
2 :: for restaurant sign in .
3 :: for create user account.
4 :: for create restaurant account.
5 :: for user password forget.
6 :: for restaurant password forget.
7 :: for quit...
------------------------------------
Your choice: 
```
## Forget Password
```
------------------------------------
1 :: for user sign in.
2 :: for restaurant sign in .
3 :: for create user account.
4 :: for create restaurant account.
5 :: for user password forget.
6 :: for restaurant password forget.
7 :: for quit...
------------------------------------
Your choice: 5
Username : pudukiye
Please Note Your Password : 123123
------------------------------------
```
## Sign in and Choose Restaurant
---
Avaliable Restaurants will be showed here (no limit)
---
```
------------------------------------
1 :: for user sign in.
2 :: for restaurant sign in .
3 :: for create user account.
4 :: for create restaurant account.
5 :: for user password forget.
6 :: for restaurant password forget.
7 :: for quit...
------------------------------------
Your choice: 1
Username : pudukiye
Password : 123123
Singing...
Restaurants 
1. Restaurant Name : Burger King
--------------------------
```
## Customer Menu
```
-----------------------------
1 :: for Order :
2 :: for Order History :
3 :: for Top-up Account :
4 :: for Change Personal Data :
5 :: for Customer Service :
6 :: for Suggest Me Meal :
7 :: for Apply Promo Code : 
8 :: for Quit :
-----------------------------
Your choice : 
```
## Ordering and Top-Up Balance
```
-----------------------------
1 :: for Order :
2 :: for Order History :
3 :: for Top-up Account :
4 :: for Change Personal Data :
5 :: for Customer Service :
6 :: for Suggest Me Meal :
7 :: for Apply Promo Code : 
8 :: for Quit :
-----------------------------
Your choice : 1
Menu :: 
-------------------------
1. Product Name : Big Mac
1. Product Price : 19.99
2. Product Name : Fries
2. Product Price : 9.99
-------------------------
Your Choice :: 1
Big Mac
Opps! You dont have enough money in your account.
Please Top-up. 

Current Balance in Your Account
1. Balance : 10
How much you want to add your account  
40
Top-up Balance set to : 40
Current Saved Cards.
1. Card Number : 5593-4323-5674-2345
2. Card Number : 9826-4243-5674-2347
Would you like to use saved card :: (Y - N)y
Which card :
1
Card choosen :: 1
You added 40 to your balance.
-----------------------------
1 :: for Order :
2 :: for Order History :
3 :: for Top-up Account :
4 :: for Change Personal Data :
5 :: for Customer Service :
6 :: for Suggest Me Meal :
7 :: for Apply Promo Code : 
8 :: for Quit :
-----------------------------
Your choice : 1
Menu :: 
-------------------------
1. Product Name : Big Mac
1. Product Price : 19.99
2. Product Name : Fries
2. Product Price : 9.99
-------------------------
Your Choice :: 1
You ordered : Big Mac
Your order will be delivered in 15-25M
-----------------------------
```
## Promo Code 
```
-----------------------------
1 :: for Order :
2 :: for Order History :
3 :: for Top-up Account :
4 :: for Change Personal Data :
5 :: for Customer Service :
6 :: for Suggest Me Meal :
7 :: for Apply Promo Code : 
8 :: for Quit :
-----------------------------
Your choice : 7
-------------------------
Enter Your Promo Code : puduk12
Promo code already used. 
-----------------------------
```
## Restaurant Menu
```
------------------------------------
1 :: for user sign in.
2 :: for restaurant sign in .
3 :: for create user account.
4 :: for create restaurant account.
5 :: for user password forget.
6 :: for restaurant password forget.
7 :: for quit...
------------------------------------
Your choice: 2
------------------
Restaurant Name : Burger King
Restaurant Password : 123123
Welcome.Burger King
--------------------------
0 :: for quit
1 :: for add product.
2 :: for delete product.
3 :: for update porsion.
4 :: for update price.
5 :: for create promotion.
6 :: for stock check.
7 :: for stock update.
8 :: for close restaurant.
9 :: for open restaurant.
-------------------------
```
## Add Product and Stock 
---
⚠️ If the product already exists in stock, you cannot add it again. The system will automatically check for duplicates.
To increase the quantity, please use the Stock Update feature instead.
---

```
-------------------------
1
-----------------
Product Name : Crispy Burger
Product Price : 23.99
Calories : 600
Product Porsion (500gr..) : 555
Any Alergetic Reaction : gluten and lactose
Your product Crispy Burger Successfully added.
-------------------------
How many items you need for (ex. 4) Crispy Burger
4
Enter Item name : 
onion
How many onion You have : 
50
Enter Item name : 
papper
How many papper You have : 
20
Enter Item name : 
spicy
How many spicy You have : 
5
Enter Item name : 
garlic
How many garlic You have : 
10
All 4 items have been added.
-------------------------
```
## Stock Update
```
-------------------------
7
Your Current Items : 
1. Item name : bread
1. Item amount : 18
2. Item name : meat
2. Item amount : 7
3. Item name : cheese
3. Item amount : 7
4. Item name : pickle
4. Item amount : 7
5. Item name : salt
5. Item amount : 9
6. Item name : fries
6. Item amount : 9
7. Item name : onion
7. Item amount : 50
8. Item name : papper
8. Item amount : 20
9. Item name : spicy
9. Item amount : 5
10. Item name : garlic
10. Item amount : 10
-------------------------
Your Choice : 9
Whats the new amount for  : 50
Item  amount updated to 50
-------------------------
```

## Close the Restaurant 
```
0 :: for quit
1 :: for add product.
2 :: for delete product.
3 :: for update porsion.
4 :: for update price.
5 :: for create promotion.
6 :: for stock check.
7 :: for stock update.
8 :: for close restaurant.
9 :: for open restaurant.
-------------------------
8
Restaurant Statu Changed to : CLOSED 
-------------------------
```

## Quitting The System 
```
-------------------------
0
-------------------------------------
Thank you for using this application!
Rate it! Before Quit (1 - 10)
-------------------------------------
6
Goodbye from : Burger King
```
## 📄 License

This project is licensed under the [MIT License](LICENSE).  
Feel free to use, modify, and distribute with proper attribution.


