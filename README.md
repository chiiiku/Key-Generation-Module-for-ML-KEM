ML-KEM Key Generation – Cadence Stratus HLS Implementation

Overview
This repository contains the High-Level Synthesis (HLS) implementation of the Key-Generation module for ML-KEM using Cadence Stratus.
The focus is on optimizing resource usage while maintaining performance for cryptographic operations.

Key Features
Single unified hash module supporting:

SHA3-512

SHA3-256

SHAKE256

SHAKE128

Single zeta table shared between:

Multiplication

Number Theoretic Transform (NTT)

Indexed arithmetic (multiply/divide operations) is performed using bit shifting.

Barrett reduction for modular multiplication.

Small LUT-based instead of mod operation in the Keccak implementation.
