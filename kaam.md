# DBMS FISAC IA4
> ## Submitted by: 230953372_Suniket Sen_CCE - A_40
# Dataset Description

The dataset used consists of student records, where each document contains the following fields:
- `name`: The student's full name
- `age`: The student's age
- `course`: The course the student is enrolled in
- `submitted_by`: The registration number of the student who submitted the dataset
  The dataset aims to store and retrieve student details efficiently using MongoDB queries for retrieval, filtering, sorting, projection, aggregation, updates, and deletion operations.

## Dataset in JSON Format
```json
[
    { "name": "John Doe", "age": 25, "course": "Computer Science", "submitted_by": "230953372_Suniket" },
    { "name": "Jane Smith", "age": 22, "course": "Electrical Engineering", "submitted_by": "230953372_Suniket" },
    { "name": "Alice Johnson", "age": 23, "course": "Mechanical Engineering", "submitted_by": "230953372_Suniket" },
    { "name": "Bob Williams", "age": 24, "course": "Civil Engineering", "submitted_by": "230953372_Suniket" },
    { "name": "Eve Adams", "age": 21, "course": "Computer Science", "submitted_by": "230953372_Suniket" },
    { "name": "Charlie Brown", "age": 22, "course": "Data Science", "submitted_by": "230953372_Suniket" },
    { "name": "David Miller", "age": 24, "course": "AI & ML", "submitted_by": "230953372_Suniket" },
    { "name": "Sophia White", "age": 23, "course": "Cybersecurity", "submitted_by": "230953372_Suniket" },
    { "name": "Liam Scott", "age": 22, "course": "Software Engineering", "submitted_by": "230953372_Suniket" },
    { "name": "Emma Thomas", "age": 25, "course": "Robotics", "submitted_by": "230953372_Suniket" }
]
```

# MongoDB Queries Executed

### **Basic Retrieval**
Retrieve all documents from the collection:
```javascript
db["230953372_COLLECTION"].find().pretty()
```
![Screenshot 2025-04-05 011356](https://github.com/user-attachments/assets/1a4b43ba-8c61-4aca-8ba5-a817482f0066)


### **Filtering**
Find all students enrolled in "Computer Science":
```javascript
db["230953372_COLLECTION"].find({ course: "Computer Science" }).pretty()
```
![Screenshot 2025-04-05 011439](https://github.com/user-attachments/assets/94f844a5-db66-457c-a37e-9878f8e5e330)

### **Sorting**
Retrieve all documents sorted by `age` in ascending order:
```javascript
db["230953372_COLLECTION"].find().sort({ age: 1 }).pretty()
```
![Screenshot 2025-04-05 011728](https://github.com/user-attachments/assets/4851c1af-ac58-46cb-8755-e6df3867afcd)

### **Projection**
Retrieve only the `name` and `course` fields:
```javascript
db["230953372_COLLECTION"].find({}, { name: 1, course: 1, _id: 0 }).pretty()
```
![Screenshot 2025-04-05 011903](https://github.com/user-attachments/assets/00f5cba9-6cb0-4dc7-8526-d80a01cdc428)

### **Aggregation**
Count the number of students per course:
```javascript
db["230953372_COLLECTION"].aggregate([
  { $group: { _id: "$course", total_students: { $sum: 1 } } }
])
```
![Screenshot 2025-04-05 011932](https://github.com/user-attachments/assets/f6dcc187-07f1-43c3-b077-93411bc54695)

### **Update**
Change "John Doe’s" course to AI & ML:
```javascript
db["230953372_COLLECTION"].updateOne(
  { name: "John Doe" },
  { $set: { course: "AI & ML" } }
)

```
![Screenshot 2025-04-05 012021](https://github.com/user-attachments/assets/e8ce9842-7f4d-44bd-ab2e-0c8fcd6a6659)

### **Deletion**
Delete all students from "Electrical Engineering":
```javascript
db["230953372_COLLECTION"].deleteMany({ course: "Electrical Engineering" })

```
![Screenshot 2025-04-05 012128](https://github.com/user-attachments/assets/8c6b4205-e4b8-4674-8b98-44e52853e2ab)



