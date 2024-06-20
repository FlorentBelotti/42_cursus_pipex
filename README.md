<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>

<h1>42_cursus_Pipex</h1>

<p>Pipex is a project that explores the detailed programming of a Unix mechanism that you may already be familiar with. The objective is to handle pipes and redirect the input and output of commands, mimicking the behavior of shell pipelines.</p>

<h2>Table of Contents</h2>
<ul>
    <li><a href="#installation">Installation</a></li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#features">Features</a></li>
    <li><a href="#code-overview">Code Overview</a></li>
</ul>

<h2 id="installation">Installation</h2>
<p>To install and run the Pipex project, follow these steps:</p>
<ol>
    <li>Clone the repository:</li>
    <pre><code>git clone https://github.com/yourusername/pipex.git</code></pre>
    <li>Navigate to the project directory:</li>
    <pre><code>cd pipex</code></pre>
    <li>Compile the project using the provided Makefile:</li>
    <pre><code>make</code></pre>
</ol>

<h2 id="usage">Usage</h2>
<p>To use the Pipex program, run the following command:</p>
<pre><code>./pipex file1 cmd1 cmd2 file2</code></pre>
<p>Example:</p>
<pre><code>./pipex infile "ls -l" "wc -l" outfile</code></pre>
<p>This command is equivalent to the shell command:</p>
<pre><code>&lt; infile ls -l | wc -l &gt; outfile</code></pre>

<h2 id="features">Features</h2>
<ul>
    <li>Handles pipes and redirects the input and output of commands.</li>
    <li>Mimics the behavior of the following shell command:
        <pre><code>&lt; file1 cmd1 | cmd2 &gt; file2</code></pre>
    </li>
    <li>Supports various Unix system calls such as <code>open</code>, <code>close</code>, <code>read</code>, <code>write</code>, <code>malloc</code>, <code>free</code>, <code>perror</code>, <code>strerror</code>, <code>access</code>, <code>dup</code>, <code>dup2</code>, <code>

execve</code>, <code>exit</code>, <code>fork</code>, <code>pipe</code>, <code>unlink</code>, <code>wait</code>, and <code>waitpid</code>.</li>
    <li>Bonus features:
        <ul>
            <li>Handles multiple pipes.</li>
            <li>Handles the "here_doc" functionality.</li>
        </ul>
    </li>
</ul>
<h2 id="code-overview">Code Overview</h2>
<p>The project is organized into several source files, each handling different aspects of the program:</p>
<ul>
    <li><code>pipex.c</code>: Contains the main function and program entry point.</li>
    <li><code>handle_process.c</code>: Manages the creation and execution of child processes.</li>
    <li><code>handle_path.c</code>: Handles path resolution for executable commands.</li>
    <li><code>pipex_bonus.c</code>: Contains additional functionality for handling multiple pipes and "here_doc".</li>
    <li><code>bonus_utils.c</code>: Utility functions for bonus features.</li>
    <li><code>bonus_handle_process.c</code>: Manages processes for the bonus part of the project.</li>
    <li><code>bonus_handle_path.c</code>: Handles path resolution for bonus features.</li>
    <li><code>bonus_handle_here_doc.c</code>: Manages the "here_doc" functionality.</li>
</ul>
    <h2>Feedback</h1>
    <p>
        The Pipex project is not a significant technical challenge. The real challenge lies in understanding the use and functioning of pipes in a shell and in a C program. It is often recommended to complete Pipex before tackling Minishell, as the latter also uses this concept. I would make the same suggestion.
    </p>
    <p>
        Implementing Pipex and its bonuses is generally not very difficult. The most time-consuming part is understanding and mastering the use of processes in a C program. Once you grasp this logic, the rest of the project becomes relatively straightforward to implement.
    </p>
    <p>
    <h2>Thanks</h1>
        To <a href="https://github.com/JayZ66">Jeguerin (JayZ66)</a>: who greatly helped me understand the functionality and utility of pipes. Having already completed this project, she allowed me to build on hers and explained its workings so that I could develop my own.
    </p>
</body>
</html>
</body>
</html>
