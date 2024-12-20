#ifndef result_h
#define result_h

// typedef enum e_result t_result;

enum e_result
{
	// ok
	e_result_ok,
	// error
	e_result_allocation_err, // メモリの割当に失敗したときのエラー
	e_result_load_err, // 不正なファイルを読み込んだ際のエラー
	e_result_index_out_of_range_err,
	e_result_io_err,
};

#endif
