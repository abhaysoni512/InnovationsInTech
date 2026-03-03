SHA-1 or Secure Hash Algorithm 1 is a cryptographic algorithm that takes an input and produces a 160-bit (20-byte) hash value. This hash value is known as a message digest. This message digest is usually then rendered as a hexadecimal number which is 40 digits long. It is a U.S. Federal Information Processing Standard and was designed by the United States National Security Agency. SHA-1 is been considered insecure since 2005. Major tech giants browsers like Microsoft, Google, Apple, and Mozilla have stopped accepting SHA-1 SSL certificates by 2017.


# How SHA-1 Works

The block diagram of the SHA-1 (Secure Hash Algorithm 1) algorithm. Here’s a detailed description of each component and process in the diagram:

Components and Process Flow:
Message (M):
The original input message that needs to be hashed.
Message Padding:
The initial step where the message is padded to ensure its length is congruent to 448 modulo 512. This step prepares the message for processing in 512-bit blocks.
Round Word Computation (WtW_tWt​):
After padding, the message is divided into blocks of 512 bits, and each block is further divided into 16 words of 32 bits. These words are then expanded into 80 32-bit words, which are used in the subsequent rounds.
Round Initialize (A, B, C, D, and E):
Initialization of five working variables (A, B, C, D, and E) with specific constant values. These variables are used to compute the hash value iteratively.
Round Constants (KtK_tKt​):
SHA-1 uses four constant values (K1K_1K1​, K2K_2K2​, K3K_3K3​, K4K_4K4​), each applied in a specific range of rounds:
K1K_1K1​ for rounds 0-19
K2K_2K2​ for rounds 20-39
K3K_3K3​ for rounds 40-59
K4K_4K4​ for rounds 60-79
Rounds (0-79):
The main computation loop of SHA-1, divided into four stages (each corresponding to one of the constants K1K_1K1​ to K4K_4K4​). In each round, a combination of logical functions and operations is performed on the working variables (A, B, C, D, and E) using the words generated in the previous step.
Final Round Addition:
After all 80 rounds, the resulting values of A, B, C, D, and E are added to the original hash values to produce the final hash.
MPX (Multiplexing):
Combines the results from the final round addition to form the final message digest.