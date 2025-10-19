# Repository Issues and Improvements Log

This document tracks all identified issues, errors, and improvements made to the school repository.

## Critical Errors Fixed

### 1. CMake Variable Naming Inconsistency in practice-3

**Location**: `subjects/programmable-logic-devices/practices/practice-3/cmake/practice-3/default.production/.generated/`

**Issue**: Variable names in CMake files used hyphens (`practice-3`) instead of underscores (`practice_3`), which is inconsistent with CMake naming conventions and other practice configurations.

**Files Affected**:
- `file.cmake`
- `main.cmake`
- `rule.cmake`

**Impact**: 
- Could cause build failures or undefined variable errors
- Inconsistent with practice-1 and practice-4 naming conventions
- Violates CMake best practices for variable naming

**Resolution**: 
- Replaced all instances of `practice-3` with `practice_3` in variable names
- Maintained consistency with other practice configurations
- Path references (e.g., `out/practice-3/production`) correctly kept with hyphens

**Changed Variable Names**:
- `practice-3_default_*` → `practice_3_default_*`
- All function names, targets, and variable references updated

## Missing Documentation Added

### 2. Missing README for practice-4

**Location**: `subjects/programmable-logic-devices/practices/practice-4/`

**Issue**: practice-4 had no README.md file, unlike practice-1 and practice-3

**Resolution**: Created README.md with:
- Project structure documentation
- Directory purpose descriptions
- Consistent formatting with other practice READMEs

### 3. Missing Subject-Level Documentation

**Issue**: No overview documentation existed for subject directories

**Resolution**: Created comprehensive README.md files for:

#### `subjects/programmable-logic-devices/README.md`
- Course overview
- Development environment setup
- Practice descriptions
- Build instructions
- File structure explanation

#### `subjects/design-of-mechanisms-assisted-by-computer/README.md`
- Course overview
- CAD tools information
- Practice descriptions
- File format documentation

### 4. Enhanced Main Repository README

**Location**: Root `README.md`

**Improvements**:
- Added complete repository structure tree
- Created navigation links to subject READMEs
- Documented organizational standards
- Added getting started guide
- Improved overall clarity and organization

## Repository Organization Improvements

### Documentation Standards Established

1. **Practice-Level Documentation**:
   - Each practice must have a README.md
   - Standard structure table included
   - Purpose and usage clearly documented

2. **Subject-Level Documentation**:
   - Overview of course content
   - Development environment requirements
   - List of available practices with descriptions
   - File format explanations

3. **Repository-Level Documentation**:
   - Complete structure overview
   - Navigation aids
   - Clear purpose statements
   - Contributing guidelines

### File Naming Conventions

**CMake Variables**: 
- Use underscores (`practice_1`, `practice_3`, `practice_4`)
- Consistent across all configuration files

**Directory Names**: 
- Use hyphens for directory names (`practice-1`, `practice-3`, `practice-4`)
- Lowercase for consistency

**Documentation Files**:
- `README.md` for all directories with multiple items
- Uppercase for markdown files

## Summary

**Total Issues Fixed**: 4
- 1 Critical error (CMake variable naming)
- 3 Missing documentation items

**Total Files Modified**: 4
**Total Files Created**: 4

**Status**: ✅ All identified errors documented and resolved

## Maintenance Notes

### Generated Files
The `.generated` directories in CMake configurations contain auto-generated files. If these are regenerated:
- Verify variable naming conventions are maintained
- Check consistency with manual configurations
- Update this log if new issues are discovered

### Future Additions
When adding new practices:
1. Follow the established directory structure
2. Create README.md with standard format
3. Use underscore naming for CMake variables
4. Use hyphen naming for directory names
5. Update subject-level README with practice description

## Verification Checklist

- [x] All CMake variable names use underscores
- [x] All practices have README.md files
- [x] All subjects have README.md files
- [x] Root README provides complete navigation
- [x] Documentation standards are consistent
- [x] File naming conventions are documented
- [x] Error log is comprehensive and clear
