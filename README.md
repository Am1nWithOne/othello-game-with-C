<h1>Othello Game in C ( SUT - Basic Programming Course )</h1>

<p>This C program implements the classic two-player strategy board game Othello playable in the terminal.  This project was created for a basic programming course at SUT (insert full name of university here, if applicable).</p>

<h2>Running the Code</h2>

<p>1. **Compile the code:** You'll need a C compiler like GCC. Open your terminal and navigate to the directory containing your C source file (e.g., `othello.c`). Then, run the following command:</p>

<pre>gcc othello.c -o othello</pre>

<p>Replace `othello.c` with your actual file name. This creates an executable file named `othello`.</p>

<p>2. **Run the game:** Once compiled, execute the game with:</p>

<pre>./othello</pre>

<p>The program will prompt you to choose between Singleplayer or Multiplayer mode.</p>

<h2>Gameplay</h2>

<p>Othello is played on an 8x8 board with black and white discs. Players take turns placing their colored discs on the board. A disc can be flipped to your color if it flanks an opponent's disc between two of your own discs in a straight line (horizontal, vertical, or diagonal). The game ends when no valid moves remain for either player. The player with the most discs of their color on the board wins!</p>

<h2>Additional Notes</h2>

<ul>
  <li>In Singleplayer mode, you play against a computer AI.</li>
  <li>In Multiplayer mode, you play against another human player on the same machine.</li>
</ul>

<p>I hope this README provides a clear explanation of how to run and play your Othello game!</p>
