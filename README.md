<div align="left">

### 42_cursus_Pipex![---------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)

<div align="left">

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)

<nav>
    
### Summary![---------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)

<ul>
    <li><a href="#installation">Installation</a></li>
    <li><a href="#features">Features</a></li>
    <li><a href="#code-overview">Code Overview</a></li>
    <li><a href="#feedback">Feedback</a></li>
    <li><a href="#thanks">Thanks</a></li>
</ul>
</nav>

### Usage![---------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)
<section id="usage">

<p>To use the Pipex program, run the following command:</p>
<pre><code>./pipex file1 cmd1 cmd2 file2</code></pre>
<p>Example:</p>
<pre><code>./pipex infile "ls -l" "wc -l" outfile</code></pre>
<p>This command is equivalent to the shell command:</p>
<pre><code>&lt; infile ls -l | wc -l &gt; outfile</code></pre>
</section>

### Features![---------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)
<section id="features">

<ul>
    <li>Handles pipes and redirects the input and output of commands.</li>
    <li>Mimics the behavior of the following shell command:
        <pre><code>&lt; file1 cmd1 | cmd2 &gt; file2</code></pre>
    </li>
    <li>Supports various Unix system calls such as <code>open</code>, <code>close</code>, <code>read</code>, <code>write</code>, <code>malloc</code>, <code>free</code>, <code>perror</code>, <code>strerror</code>, <code>access</code>, <code>dup</code>, <code>dup2</code>, <code>execve</code>, <code>exit</code>, <code>fork</code>, <code>pipe</code>, <code>unlink</code>, <code>wait</code>, and <code>waitpid</code>.</li>
    <li>Bonus features:
        <ul>
            <li>Handles multiple pipes.</li>
            <li>Handles the "here_doc" functionality.</li>
        </ul>
    </li>
</ul>
</section>

### Code Overview![---------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)
<section id="code-overview">

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
</section>

### Feedback![---------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)
<section id="feedback">

<p>
    The Pipex project is not a significant technical challenge. The real challenge lies in understanding the use and functioning of pipes in a shell and in a C program. It is often recommended to complete Pipex before tackling Minishell, as the latter also uses this concept. I would make the same suggestion.
</p>
<p>
    Implementing Pipex and its bonuses is generally not very difficult. The most time-consuming part is understanding and mastering the use of processes in a C program. Once you grasp this logic, the rest of the project becomes relatively straightforward to implement.
</p>
</section>

### Thanks![---------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)
<section id="thanks">

<p>
    To <a href="https://github.com/JayZ66">Jeguerin (JayZ66)</a>: who greatly helped me understand the functionality and utility of pipes. Having already completed this project, she allowed me to build on hers and explained its workings so that I could develop my own.
</p>
</section>
</div>
