#pragma once

#define MYCHECKNULL2(__pointer_to_check__, statement)\
do { if (__pointer_to_check__ == nullptr) { \
	UE_LOG(LogTemp, Error, TEXT("null pointer: " #__pointer_to_check__));\
	statement;\
	} } while (false)

#define MYCHECKNULL(__pointer_to_check__) MYCHECKNULL2(__pointer_to_check__, return)
