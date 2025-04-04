# MongoDB Atlas Report

## 1. Dataset Description

The dataset used consists of student records, where each document contains the following fields:
- `name`: The student's full name
- `age`: The student's age
- `course`: The course the student is enrolled in
- `submitted_by`: The registration number of the student who submitted the dataset

### Dataset in JSON Format
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

## 2. MongoDB Queries Executed

### **Basic Retrieval**
Retrieve all documents from the collection:
```javascript
db["230953372_COLLECTION"].find().pretty()
```

### **Filtering**
Find all students enrolled in "Computer Science":
```javascript
db["230953372_COLLECTION"].find({ course: "Computer Science" }).pretty()
```

### **Sorting**
Retrieve all documents sorted by `age` in ascending order:
```javascript
db["230953372_COLLECTION"].find().sort({ age: 1 }).pretty()
```

### **Projection**
Retrieve only the `name` and `course` fields:
```javascript
db["230953372_COLLECTION"].find({}, { name: 1, course: 1, _id: 0 }).pretty()
```

### **Aggregation**
Count the number of students per course:
```javascript
db.230953372_COLLECTION.aggregate([
    { $group: { _id: "$course", count: { $sum: 1 } } }
])
```

### **Update**
Change "John Doe’s" course to AI & ML:
```javascript
db["230953372_COLLECTION"].updateOne(
  { name: "John Doe" },
  { $set: { course: "AI & ML" } }
)

```

### **Deletion**
Delete all students from "Electrical Engineering":
```javascript
db["230953372_COLLECTION"].deleteMany({ course: "Electrical Engineering" })

```

## 3. Screenshots
(Add your screenshots of MongoDB query results here)

---
**Submission by:** 230953372_Suniket
