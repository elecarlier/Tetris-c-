Key Classes
1. Piece

Represents a single Tetris piece (tetromino).

Header: Piece.hpp

    Members

        int type – The type of tetromino (0-6 for the 7 standard shapes)

        int rotation – Current rotation (0-3)

        int x, y – Coordinates of the pivot block on the board

        static const int pivot_i, pivot_j – Pivot offsets within the tetromino matrix

    Methods

        MoveLeft(), MoveRight(), MoveDown() – Move piece on board

        Rotate(), RotateBack() – Rotate piece clockwise / counterclockwise

        GetX(), GetY(), GetRotation(), GetType() – Accessors

        SetPosition(int x, int y), SetRotation(int r) – Set piece state

        GetBlocks() – Returns a vector of (x, y) coordinates for all blocks of the piece

        IsPivot(int x, int y) – Returns true if a block is the pivot block

    Notes:
    The pivot is used for rotations. GetBlocks() calculates positions of all blocks relative to the pivot and current rotation.

2. Tetromino

Static helper class to define all shapes and rotations.

    Members

        Defines a 2D array for each tetromino type and all its rotations.

    Methods

        generateAll() – Returns all blocks for all types and rotations

        SIZE – Standard size of the tetromino matrix (typically 5x5)

        NUM_ROT – Number of rotations (usually 4)

3. Board

Represents the Tetris board where pieces are placed.

Responsibilities

    Store the current state of the board (mBoard array)

    Detect collisions and free spaces

    Convert board coordinates to screen pixels

    Store pieces once they land

Key Methods

    StorePiece(int x, int y, int type, int rotation) – Marks blocks of a piece as filled

    IsFreeBlock(int x, int y) – Returns true if a board cell is empty

    GetXPosInPixels(int x), GetYPosInPixels(int y) – Convert board coordinates to screen coordinates for drawing

4. Game

Handles game logic and rendering.

Members

    Piece mCurrentPiece – Piece currently falling

    Piece mNextPiece – Next piece in the queue

    Board* mBoard – Pointer to the game board

    mIO – Pointer to an abstracted I/O/graphics handler

    mScreenHeight – Height of the window in pixels

Key Methods

    DrawBoard() – Draws the board and all filled blocks

    DrawPiece(const Piece&) – Draws a given piece on the screen

    DrawScene() – Draws the full scene (board + current piece + next piece)

Notes

    DrawPiece() checks if a block is the pivot to color it differently (blue).

    Positions are always converted from board coordinates to screen pixels using mBoard->GetXPosInPixels and GetYPosInPixels.

5. mIO (Abstracted I/O)

    This is an interface for drawing shapes on the screen.

    Provides methods like DrawRectangle(x1, y1, x2, y2, color) and GetScreenWidth().

    You can replace it with any graphics library later (SDL, SFML, etc.).

How Rendering Works

    DrawBoard()

        Draws the vertical limits of the board.

        Iterates over the board and draws filled blocks in red.

    DrawPiece()

        Gets all blocks of a piece with GetBlocks().

        For each block:

            Converts board coordinates to pixels

            Colors pivot block blue, others green

            Draws the rectangle on screen

    DrawScene()

        Calls DrawBoard()

        Draws the current piece

        Draws the next piece (position adjusted separately)

How Pieces Move

    Game logic updates the position of mCurrentPiece using MoveLeft/Right/Down and Rotate.

    Collision detection is done using the board (IsFreeBlock()).

    When a piece lands, StorePiece() marks the blocks as filled on the board.

Tips for Picking Up Later

    Piece handles all position and rotation logic.

    Board handles collision and conversion to pixel coordinates.

    Game handles rendering and high-level game flow.

    mIO is the only place where drawing happens, making it easy to swap graphics libraries.

    Use GetBlocks() and IsPivot() when you need to render or check collisions.
