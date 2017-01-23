/*
* Simd Library (http://simd.sourceforge.net).
*
* Copyright (c) 2011-2017 Yermalayeu Ihar.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy 
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell 
* copies of the Software, and to permit persons to whom the Software is 
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in 
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/

/*                                                                                    
* File name   : SimdHelp.h                                                       
* Description : This file contains additional information about Simd Library needed for help generated by Doxygen.                
*/

/*!
    \mainpage

    This is the reference documentation of <a href="http://simd.sourceforge.net">Simd Library</a>,
    the C++ image processing library.
    This documentation have been generated using the tool <a href="http://www.doxygen.org">doxygen</a>.
    It contains a detailed description of all classes and functions of the %Simd Library.
    If you have downloaded the %Simd Library package, you actually have a local copy of these pages in the
    \c simd/doc/help/ directory.

    Use the menu above to navigate through the documentation pages.
    As a first step, you may look at the list of <a href="modules.html">available modules</a>.
*/

/*! @defgroup simd_overview Simd Library Overview */
/*@{*/
/*!
    \page foo2

    The <b>%Simd Library</b> is a free open source image processing library, designed for C and C++ programmers.
    It provides many useful high performance algorithms for image processing such as: pixel format conversion, image scaling and filtration, 
    extraction of statistic information from images, motion detection, object detection (HAAR and LBP classifier cascades) and classification, neural network.
    
    \n\n The algorithms are optimized with using of different SIMD CPU extensions. 
    In particular the library supports following CPU extensions: SSE, SSE2, SSE3, SSSE3, SSE4.1, SSE4.2, AVX and AVX2 for x86/x64, VMX(Altivec) and VSX(Power7) for PowerPC, NEON for ARM.

    \n\n The %Simd Library has C API and also contains useful C++ classes and functions to facilitate access to C API.
    The library supports dynamic and static linking, 32-bit and 64-bit Windows and Linux, MSVS and G++ compilers, MSVS project and CMake build systems.

    \section s1 Library folder's structure

    The %Simd Library has next folder's structure:
     - \c simd/src/Simd/ - contains source codes of the library.
     - \c simd/src/Test/ - contains test framework of the library.
     - \c simd/prj/vs14/ - contains project files of Microsoft Visual Studio 2015.
     - \c simd/prj/cmd/ - contains additional scripts needed for building of the library in Windows.
     - \c simd/prj/cmake/ - contains files of CMake build systems.
     - \c simd/prj/sh/ - contains additional scripts needed for building of the library in Linux.
     - \c simd/prj/txt/ - contains text files needed for building of the library.
     - \c simd/data/cascade/ - contains OpenCV cascades (HAAR and LBP).
     - \c simd/data/image/ - contains image samples.
     - \c simd/data/network/ - contains examples of trained networks.
     - \c simd/doc/ - contains documentation of the library.
     - \c simd/doc/src/ - contains scripts for generation of this documentation by <a href="http://www.doxygen.org">doxygen</a>.

	\section s2 The library building for Windows

	To build the library and test application for Windows 32/64 you need to use Microsoft Visual Studio 2015. 
	These project files are in the directory: 
	\c simd/prj/vs14/.
	\n By default the library is built as	a DLL (Dynamic Linked Library).
	You also may build it as a static library. 
	To do this you must change appropriate property (Configuration Type) of <b>%Simd</b> project and also uncomment \#define SIMD_STATIC in file:
	\c simd/src/Simd/SimdConfig.h.

	\section s3 The library building for Linux
	To build the library and test application for Linux 32/64 you need to use CMake build systems.
	Files of CMake build systems are placed in the directory:
	\c simd/prj/cmake/.
	The library can be built for x86/x64, PowerPC and ARM platforms.
	With using of native compiler (g++) for current platform it is simple:
	\code
	cd ./prj/cmake
	cmake . -DTOOLCHAIN="" -DTARGET=""
	make
	\endcode
	To build the library for PowePC and ARM platforms you can also use toolchain for cross compilation.
	There is an example of using for PowerPC:
	\code
	cd ./prj/cmake
	cmake . -DTOOLCHAIN="/path_to_your_toolchain/usr/bin/powerpc-linux-g++" -DTARGET="ppc64" -DCMAKE_BUILD_TYPE="Release"
	make
	\endcode
	And for ARM:
	\code
	cd ./prj/cmake
	cmake . -DTOOLCHAIN="/path_to_your_toolchain/usr/bin/arm-linux-gnueabihf-g++" -DTARGET="arm" -DCMAKE_BUILD_TYPE="Release"
	make
	\endcode
	As result the library and the test application will be built in the current directory.

    \section s4 The library using

    If you use the library from C code you must include:
    \code
    #include "Simd/SimdLib.h"
    \endcode

    And to use the library from C++ code you must include:
    \code
    #include "Simd/SimdLib.hpp"
    \endcode

    In order to use Simd::Detection you must include:
    \code
    #include "Simd/SimdDetection.hpp"
    \endcode

    \section s5 Test Framework

    The test suite is needed for testing of correctness of work of the library and also for its performance testing.
	There is a set of tests for every function from API of the library. 
	There is an example of test application using:
	\code
	./Test -m=a -t=1 -f=Sobel -o=log.txt
	\endcode
	Where next parameters were used:
	 - \c -m=a - a auto checking mode which includes performance testing (only for library built in Release mode). 
	In this case different implementations of each functions will be compared between themselves 
	(for example a scalar implementation and implementations with using of different SIMD instructions such as SSE2, AVX2, and other).
	Also it can be -m=c (creation of test data for cross-platform testing), -m=v (cross-platform testing with using of early prepared test data)
    and -m=s (running of special tests).
	 - \c -t=1 - a number of used threads (every thread runs all tests) for simulation of multi-thread loading.
	 - \c -f=Sobel - a filter. In current case will be tested only functions which contain word 'Sobel' in their names. 
	If you miss this parameter then full testing will be performed.
    You can use several filters - function name has to satisfy at least one of them.
	 - \c -o=log.txt - a file name with test report. The test's report also will be output to console.
    
    Also you can use parameters:
     - \c -h or -? in order to print help message.
     - \c -r=../.. to set project root directory.
     - \c -pa=1 to print alignment statistics.
*/
/*@}*/

/*! @defgroup c_types C Types
    \short Types of %Simd Library C API.
*/

/*! @defgroup cpp_types C++ Types
    \short C++ API Types of %Simd Library.
*/

/*! @ingroup cpp_types
    @defgroup cpp_allocator Allocator
    \short Simd::Allocator structure. 
*/

/*! @ingroup cpp_types
    @defgroup cpp_point Point
    \short Simd::Point structure and related functions. 
*/

/*! @ingroup cpp_point
    @defgroup cpp_point_functions Related Functions 
    \short Related functions for Simd::Point structure. 
*/

/*! @ingroup cpp_types
    @defgroup cpp_rectangle Rectangle
    \short Simd::Rectangle structure and related functions. 
*/

/*! @ingroup cpp_rectangle
    @defgroup cpp_rectangle_functions Related Functions 
    \short Related functions for Simd::Rectangle structure. 
*/

/*! @ingroup cpp_types
    @defgroup cpp_pixels Pixels
    \short BGR, BGRA, HSL, HSV pixel structures.
*/

/*! @ingroup cpp_types
    @defgroup cpp_view View
    \short Simd::View structure and related functions. 
*/

/*! @ingroup cpp_view
    @defgroup cpp_view_functions Related Functions 
    \short Related functions for Simd::View structure. 
*/

/*! @ingroup cpp_types
    @defgroup cpp_frame Frame
    \short Simd::Frame structure and related functions.
*/

/*! @ingroup cpp_frame
    @defgroup cpp_frame_functions Related Functions
    \short Related functions for Simd::Frame structure.
*/

/*! @ingroup cpp_types
    @defgroup cpp_pyramid Pyramid
    \short Simd::Pyramid structure and related functions.
*/

/*! @ingroup cpp_pyramid
    @defgroup cpp_pyramid_functions Related Functions
    \short Related functions for Simd::Pyramid structure.
*/

/*! @ingroup cpp_types
    @defgroup cpp_detection Detection
    \short Simd::Detection structure (C++ Object Detection Wrapper).
*/

/*! @ingroup cpp_types
    @defgroup cpp_neural Neural
    \short Simd::Neural is C++ framework for running and learning of Convolutional Neural Network.
*/

/*! @ingroup cpp_types
    @defgroup cpp_contour Contour Detector
    \short Simd::ContourDetector structure and related functions.
*/

/*! @ingroup cpp_types
    @defgroup cpp_shift Shift Detector
    \short Simd::ShiftDetector structure and related functions.
*/

/*! @ingroup cpp_types
    @defgroup cpp_drawing Drawing Functions
    \short Drawing functions.
*/

/*! @defgroup functions Functions
    \short Functions of %Simd Library API.
*/

/*! @ingroup functions
    @defgroup info Info
    \short Functions with information about library.
*/

/*! @ingroup functions
    @defgroup memory Memory Utilities
    \short Functions for memory management.
*/

/*! @ingroup functions
    @defgroup hash Hash Functions
    \short Functions for hash estimation.
*/

/*! @ingroup functions
    @defgroup reordering Byte Reordering
    \short Functions for bytes reordering.
*/

/*! @ingroup functions
    @defgroup conversion Conversion
    \short Functions for image format conversions.
*/

/*! @ingroup conversion
	@defgroup universal_conversion Universal
	\short Universal functions for image format conversions.
*/

/*! @ingroup conversion
    @defgroup bayer_conversion Bayer 
    \short Functions for Bayer image conversions.
*/

/*! @ingroup conversion
    @defgroup bgr_conversion BGR-24 
    \short Functions for BGR-24 image conversions.
*/

/*! @ingroup conversion
    @defgroup bgra_conversion BGRA-32 
    \short Functions for BGRA-32 image conversions.
*/

/*! @ingroup conversion
    @defgroup gray_conversion Gray-8 
    \short Functions for Gray-8 image conversions.
*/

/*! @ingroup conversion
    @defgroup yuv_conversion YUV 
    \short Functions for YUV image conversions.
*/

/*! @ingroup conversion
    @defgroup other_conversion Other 
    \short Functions for other image format conversions.
*/

/*! @ingroup functions
    @defgroup drawing Drawing
    \short Functions for image drawing.
*/

/*! @ingroup functions
    @defgroup correlation Correlation
    \short Functions for estimation of correlation.
*/

/*! @ingroup functions
    @defgroup histogram Histogram
    \short Functions for estimation of image histogram.
*/

/*! @ingroup functions
    @defgroup integral Integral
    \short Functions for estimation of integral image.
*/

/*! @ingroup functions
    @defgroup operation Operations
    \short Various mathematical operations with images.
*/

/*! @ingroup functions
    @defgroup filter Filters
    \short Various image filters.
*/

/*! @ingroup filter
    @defgroup median_filter Median Filters
    \short Median image filters.
*/

/*! @ingroup filter
    @defgroup sobel_filter Sobel Filters
    \short Sobel image filters.
*/

/*! @ingroup filter
    @defgroup laplace_filter Laplace Filters
    \short Laplace image filters.
*/

/*! @ingroup filter
    @defgroup other_filter Other Filters
    \short Other image filters.
*/

/*! @ingroup functions
    @defgroup resizing Resizing
    \short Functions for image resizing.
*/

/*! @ingroup functions
    @defgroup shifting Shifting
    \short Functions for image shifting.
*/

/*! @ingroup functions
    @defgroup copying Copying
    \short Functions for image copying.
*/

/*! @ingroup functions
    @defgroup filling Filling
    \short Functions for image filling.
*/

/*! @ingroup functions
    @defgroup binarization Binarization
    \short Functions for image binarization.
*/

/*! @ingroup functions
    @defgroup statistic Statistic
    \short Functions for image statistic estimation.
*/

/*! @ingroup statistic
    @defgroup conditional Conditional
    \short Functions for conditional estimation of image statistic.
*/

/*! @ingroup statistic
    @defgroup col_statistic Columns Statistic
    \short Estimation of image statistic for separate columns.
*/

/*! @ingroup statistic
    @defgroup row_statistic Rows Statistic
    \short Estimation of image statistic for separate rows.
*/

/*! @ingroup statistic
    @defgroup sobel_statistic Sobel Statistic
    \short Getting of statistic related with Sobel filters.
*/

/*! @ingroup statistic
    @defgroup other_statistic Other Statistic
    \short Estimation of various image statistic.
*/

/*! @ingroup functions
    @defgroup motion_detection Motion Detection
    \short Functions for motion detection.
*/

/*! @ingroup motion_detection
    @defgroup texture_estimation Texture Estimation
    \short Functions for estimation of background texture.
*/

/*! @ingroup motion_detection
    @defgroup difference_estimation Difference Estimation
    \short Functions for estimation of difference between current frame and background.
*/

/*! @ingroup motion_detection
    @defgroup segmentation Segmentation
    \short Functions for image segmentation.
*/

/*! @ingroup motion_detection
    @defgroup interference Interference Detection
    \short Functions for detection of interference in motion detection algorithm.
*/

/*! @ingroup motion_detection
    @defgroup background Background Updating
    \short Functions for background updating.
*/

/*! @ingroup motion_detection
    @defgroup edge_background Edge Background Updating
    \short Functions for edge background updating.
*/

/*! @ingroup functions
    @defgroup face_recognition Face Recognition
    \short Functions for face recognition.
*/

/*! @ingroup functions
    @defgroup svm SVM
    \short Support Vector Machine's functions.
*/

/*! @ingroup functions
	@defgroup neural Neural Network
	\short Artificial Neural Network's functions for accelerating of Simd::Neural.
*/

/*! @ingroup functions
    @defgroup object_detection Object Detection
    \short Object Detection's low-level API for Simd::Detection.
*/

/*! @ingroup functions
    @defgroup contour Contour Extraction
    \short Contour extraction functions for accelerating of Simd::ContourDetector.
*/

#ifndef __SimdHelp_h__
#define __SimdHelp_h__
#endif//__SimdHelp_h__

