//===========================================================================
//===========================================================================
//===========================================================================
//==   vbam.cpp                                                            ==
//===========================================================================
//===========================================================================
//===========================================================================

//===========================================================================
//===========================================================================
#include "stdafx.h"
#include "Direct_Access_Image.h"
#include "constants.h"
#include "Bam.h"
#include "BamPool.h"
//===========================================================================
//===========================================================================

//===========================================================================
//===========================================================================
int _tmain(int argc, _TCHAR* argv[])
{
	// Verify command-line usage correctness
	if (argc != 7)
	{
		_tprintf(_T("Use: %s <timeout (miliseconds/pixel t1)>\n")
			_T("\t\t<timeout for init and destroy (miliseconds t2)>\n")
			_T("\t\t<folder where BAM executables are found>\n")
			_T("\t\t<input image name for BAM> <BAM output folder>\n")
			_T("\t\t<output image name> %d\n"), argv[0], argc);
		return VBAM_EXIT::ARGS_ERR;
	}

	BamPool pool(argv[3], argv[4], argv[5], argv[6]);
	pool.Init(argv[0]);
	pool.SpawnAll(argv[1], argv[2]);
	
	pool.SmartVote( 8 );
//	pool.DummyVote();

	// Return with success
	return VBAM_EXIT::SUCCESS;
}
//===========================================================================
//===========================================================================
