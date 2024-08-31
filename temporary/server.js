const express = require('express');
const fs = require('fs');
const path = require('path');

const app = express();
const PORT = 3000;
const tasksFilePath = path.join(__dirname, 'tasks.json');

// Set EJS as the templating engine
app.set('view engine', 'ejs');
app.set('views', path.join(__dirname, 'views'));

// Middleware to parse JSON and serve static files
app.use(express.json());
app.use(express.static(path.join(__dirname, 'public')));

// Load tasks from the file
const loadTasks = () => {
    try {
        const data = fs.readFileSync(tasksFilePath, 'utf8');
        return JSON.parse(data);
    } catch (err) {
        return [];
    }
};

// Save tasks to the file
const saveTasks = (tasks) => {
    fs.writeFileSync(tasksFilePath, JSON.stringify(tasks, null, 2), 'utf8');
};

// Render the to-do list
app.get('/', (req, res) => {
    const tasks = loadTasks();
    res.render('index', { tasks });
});

// Add a new task
app.post('/tasks', (req, res) => {
    const tasks = loadTasks();
    const newTask = req.body.task;
    tasks.push(newTask);
    saveTasks(tasks);
    res.status(201).json({ message: 'Task added successfully' });
});

// Delete a task
app.delete('/tasks', (req, res) => {
    let tasks = loadTasks();
    const taskToDelete = req.body.task;
    tasks = tasks.filter(task => task !== taskToDelete);
    saveTasks(tasks);
    res.json({ message: 'Task deleted successfully' });
});

// Update a task
app.put('/tasks', (req, res) => {
    let tasks = loadTasks();
    const { oldTask, newTask } = req.body;
    const taskIndex = tasks.indexOf(oldTask);
    if (taskIndex !== -1) {
        tasks[taskIndex] = newTask;
        saveTasks(tasks);
        res.json({ message: 'Task updated successfully' });
    } else {
        res.status(404).json({ message: 'Task not found' });
    }
});

app.listen(PORT, () => {
    console.log(`Server is running on http://localhost:${PORT}`);
});
