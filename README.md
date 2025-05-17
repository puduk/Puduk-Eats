# 🍔✨ Puduk Eats
🛠️ A handmade terminal-based restaurant & order ecosystem built with pure C++ and file-based logic — no SQL, no GUI, just pointer magic.

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

