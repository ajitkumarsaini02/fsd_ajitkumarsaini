// v2 — improved todo with inline edit, filters, enter-key add, counts

// DOM refs
const input = document.getElementById('taskInput');
const addBtn = document.getElementById('addBtn');
const taskList = document.getElementById('taskList');
const taskCountEl = document.getElementById('taskCount');
const completedCountEl = document.getElementById('completedCount');
const clearAllBtn = document.getElementById('clearAllBtn');
const filterBtns = Array.from(document.querySelectorAll('.filterBtn'));

addBtn.addEventListener('click', addTask);
input.addEventListener('keydown', e => { if (e.key === 'Enter') addTask(); });
clearAllBtn.addEventListener('click', clearAll);
filterBtns.forEach(b => b.addEventListener('click', () => {
    filterBtns.forEach(x => x.classList.remove('active'));
    b.classList.add('active');
    applyFilter(b.dataset.filter);
}));

loadTasks();

// — Add Task
function addTask() {
    const taskText = input.value.trim();
    if (!taskText) { alert('Enter a task!'); return; }
    createTask(taskText);
    saveTasks();
    input.value = '';
    updateCount();
}

// — Create task node
function createTask(taskText, completed = false) {
    const li = document.createElement('li');

    const left = document.createElement('div');
    left.className = 'task-left';

    // task text span
    const span = document.createElement('span');
    span.className = 'task-text';
    span.textContent = taskText;

    // inline edit input
    const editInput = document.createElement('input');
    editInput.className = 'task-edit-input';
    editInput.type = 'text';
    editInput.value = taskText;

    left.appendChild(span);
    left.appendChild(editInput);

    if (completed) li.classList.add('completed');

    // Buttons container
    const btnDiv = document.createElement('div');
    btnDiv.className = 'task-buttons';

    const done = document.createElement('button');
    done.className = 'doneBtn';
    done.textContent = '✔';
    done.title = 'Toggle complete';
    done.addEventListener('click', () => {
        li.classList.toggle('completed');
        saveTasks();
        updateCount();
    });

    const edit = document.createElement('button');
    edit.className = 'editBtn';
    edit.textContent = '✎';
    edit.title = 'Edit task';
    edit.addEventListener('click', () => {
        // toggle edit mode
        const editing = editInput.classList.toggle('active');
        if (editing) {
            span.classList.add('editing');
            editInput.classList.add('active');
            editInput.focus();
            // move caret to end
            editInput.selectionStart = editInput.value.length;
        } else {
            commitEdit();
        }
    });

    // commit edit on Enter or blur
    editInput.addEventListener('keydown', e => { if (e.key === 'Enter') { commitEdit(); } });
    editInput.addEventListener('blur', commitEdit);

    function commitEdit() {
        const val = editInput.value.trim();
        if (val === '') {
            // don't allow empty — revert to previous or delete
            editInput.value = span.textContent;
        } else {
            span.textContent = val;
        }
        span.classList.remove('editing');
        editInput.classList.remove('active');
        saveTasks();
        updateCount();
    }

    const del = document.createElement('button');
    del.className = 'delBtn';
    del.textContent = '🗑';
    del.title = 'Delete task';
    del.addEventListener('click', () => {
        if (confirm('Delete this task?')) {
            li.remove();
            saveTasks();
            updateCount();
        }
    });

    btnDiv.appendChild(done);
    btnDiv.appendChild(edit);
    btnDiv.appendChild(del);

    li.appendChild(left);
    li.appendChild(btnDiv);
    taskList.appendChild(li);

    applyFilter(getActiveFilter());
}

// — Save / Load
function saveTasks() {
    const tasks = Array.from(document.querySelectorAll('#taskList li')).map(li => {
        const text = li.querySelector('.task-text').textContent;
        const completed = li.classList.contains('completed');
        return { text, completed };
    });
    localStorage.setItem('todoTasks', JSON.stringify(tasks));
}

function loadTasks() {
    const saved = localStorage.getItem('todoTasks');
    if (saved) {
        JSON.parse(saved).forEach(t => createTask(t.text, t.completed));
    }
    updateCount();
}

// — Clear all
function clearAll() {
    if (!taskList.children.length) { alert('No tasks to clear.'); return; }
    if (confirm('Are you sure you want to delete ALL tasks?')) {
        taskList.innerHTML = '';
        saveTasks();
        updateCount();
    }
}

// — Counts & Filter
function updateCount() {
    const total = document.querySelectorAll('#taskList li').length;
    const completed = document.querySelectorAll('#taskList li.completed').length;
    taskCountEl.textContent = total;
    completedCountEl.textContent = completed;
    applyFilter(getActiveFilter());
}

function applyFilter(filter) {
    Array.from(taskList.children).forEach(li => {
        li.style.display = (filter === 'all') ? '' :
                          (filter === 'active' && li.classList.contains('completed')) ? 'none' :
                          (filter === 'completed' && !li.classList.contains('completed')) ? 'none' : '';
    });
}

function getActiveFilter() {
    const active = document.querySelector('.filterBtn.active');
    return active ? active.dataset.filter : 'all';
}
